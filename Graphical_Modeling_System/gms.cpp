#include "gms.h"


GMS::GMS()
{
    isWorking = true;
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::HomeMenuKey,new HomeStateMenu(this)));
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::GMSMenuKey,new GMSStateMenu(this)));
    this->textMenuManager.insert(map<int,TextStateMenu*>::value_type(TextMenuKey::GroupMenuKey,new GroupStateMenu(this)));
    this->currentTextMenu = textMenuManager[TextMenuKey::HomeMenuKey];
}
//主流程 操控選單的畫面顯示與邏輯輸入
void GMS::RunGMS(){
    while(this->isWorking){
        //透過State Pattern的方式切換選單
        this->currentTextMenu->DisplayMenu();
        this->currentTextMenu->GetInput();
        this->currentTextMenu->Update();
    }
}
void GMS::SetCloseSystem(){
    this->isWorking = false;
}
void GMS::SwitchToOtherMenu(int Key){
    //把現在的選單指標指向 要切換的選單(透過map的key值取得value->選單類別 )
    this->currentTextMenu = textMenuManager[Key];
}

//把components 與groups存入檔案
int GMS::SaveXMLFormatRecord(string path){
    return model.SaveXMLFormatRecord(path);
}
//載入components與groups
int GMS::LoadXMLFormatRecord(string path){
    int code = model.LoadXMLFormatRecord(path);
    if(code == XMLErrorCode::OK){
        cmdManager.ClearCmd();
    }
    return code;
}

void GMS::EditComponentNameByCommand(int id, string newName){
    EditComponentNameCommand *editNameCmd = new EditComponentNameCommand(&model,id,newName);
    cmdManager.execute(editNameCmd);
}
void GMS::EditComponentTypeByCommand(int id, string newType){
    EditComponentTypeCommand *editTypeCmd = new EditComponentTypeCommand(&model,id,newType);
    cmdManager.execute(editTypeCmd);

}
void GMS::AddComponentsByCommand(string componentType, string componentName){

    //使用Command加入
    AddComponentCommand* addCmd = new AddComponentCommand(&model,componentType,componentName);
    cmdManager.execute(addCmd);

}
//刪除Component與判斷有無存在
bool GMS::DeleteComponentByCommand(int id){
    if(this->model.GetComponents().CheckIDHasBeenExisted(id)){
        //使用Command刪除
        DeleteComponentCommand* delCmd = new DeleteComponentCommand(&model,id);
        cmdManager.execute(delCmd);

        return true; //告知有刪除掉
    }
    return false; //沒有刪除掉 因為不存在
}
//取得所有Components
Components GMS::GetComponents(){
    return this->model.GetComponents();
}
//取得目前生產的ComponentsID
int GMS::GetCurrentComponentMakerID(){
    return this->model.GetComponents().GetCurrentGeneratedComponentID();
}
//取得目前生產的GroupID
int GMS::GetCurrentGroupMakerID(){
    return this->model.GetGroups().GetCurrentGeneratedGroupId();
}

//判斷group有無存在
bool GMS::CheckGroupHasBeenExisted(int groupId){
    return this->model.GetGroups().CheckGroupHasBeenExisted(groupId);
}

//判斷這個ComponentID有無存在Components
bool GMS::CheckComponentIDHasBeenExisted(int id){
    return this->model.GetComponents().CheckIDHasBeenExisted(id);
}
//取得所有Group
map<string,Group*> GMS::GetGroups(){
    return this->model.GetGroups().GetAllGroups();
}


//判斷這個MemberId是否存在指定的groupId(使用前請先透過 CheckGroupHasBeenExisted判斷Group有無存在)
bool GMS::CheckMemberIDHasBeenTheGroup(int groupId, int memberId){
    Group* g =  this->model.GetGroups().GetGroup(groupId);
    return  g->CheckMemberHasBeenExisted(memberId);

}
//加入新的Group
void GMS::AddNewGroupByCommand(string name, vector<int> members){
    //使用Command加入新的Group
    AddNewGroupCommand* addGroupCmd = new AddNewGroupCommand(&model,name,members);
    cmdManager.execute(addGroupCmd);

}

//取得想要的Group
Group* GMS::FindGroupByGroupId(int groupId){
    return this->model.GetGroups().GetGroup(groupId);

}
//加入members ID到Group
void GMS::AddMembersToGroupByCommand(int groupId, vector<int> members){
    //使用Command加入Members到指定的Group
    AddMembersToGroupCommand* addMembersCmd = new AddMembersToGroupCommand(&model,groupId,members);
    cmdManager.execute(addMembersCmd);

}
bool GMS::Redo(){
   return cmdManager.redo();
}
bool GMS::Undo(){
   return cmdManager.undo();
}
void GMS::ClearCommand(){
   cmdManager.ClearCmd();
}
