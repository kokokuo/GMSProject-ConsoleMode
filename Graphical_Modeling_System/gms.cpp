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
    return xmlManager.SaveXML(path,components,groups);
}
//載入components與groups
int GMS::LoadXMLFormatRecord(string path){
    components.ClearComponents(); //清除原先的Components
    groups.ClearAllGroup(); //清除原先的Group
    cmdManager.ClearCmd(); //清除指令(重新開始)

    int code = xmlManager.LoadXML(path,&components,&groups);

    return code;
}

void GMS::AddComponents(string componentType, string componentName){

    //使用Command加入
    AddComponentCommand* addCmd = new AddComponentCommand(&components,componentType,componentName);
    cmdManager.execute(addCmd);

    //Component *component = new Component(components.GetCurrentGeneratedComponentID(),componentType,componentName);
    //components.AddComponentToList(component);
    //components.AddComponentID();
}
//刪除Component與判斷有無存在
bool GMS::DeleteComponent(int id){
    if(this->components.CheckIDHasBeenExisted(id)){
        //使用Command刪除
        DeleteComponentCommand* delCmd = new DeleteComponentCommand(&components,id);
        cmdManager.execute(delCmd);
        //this->components.DeleteComponentFromList(id);
        return true; //告知有刪除掉
    }
    return false; //沒有刪除掉 因為不存在
}
//取得所有Components
vector<Component*> GMS::GetComponents(){
    return this->components.GetComponts();
}
//取得目前生產的ComponentsID
int GMS::GetCurrentComponentMakerID(){
    return this->components.GetCurrentGeneratedComponentID();
}
//取得目前生產的GroupID
int GMS::GetCurrentGroupMakerID(){
    return this->groups.GetCurrentGeneratedGroupId();
}

//判斷group有無存在
bool GMS::CheckGroupHasBeenExisted(int groupId){
    return this->groups.CheckGroupHasBeenExisted(groupId);
}

//判斷這個ComponentID有無存在Components
bool GMS::CheckComponentIDHasBeenExisted(int id){
    return this->components.CheckIDHasBeenExisted(id);
}
//取得所有Group
map<string,Group*> GMS::GetGroups(){
    return groups.GetGroups();
}


//判斷這個MemberId是否存在指定的groupId(使用前請先透過 CheckGroupHasBeenExisted判斷Group有無存在)
bool GMS::CheckMemberIDHasBeenTheGroup(int groupId, int memberId){
    Group* g =  groups.GetGroup(groupId);
    return  g->CheckMemberHasBeenExisted(memberId);

}
//加入新的Group
void GMS::AddNewGroup(string name, vector<int> members){
    //使用Command加入新的Group
    AddNewGroupCommand* addGroupCmd = new AddNewGroupCommand(&groups,name,members);
    cmdManager.execute(addGroupCmd);
    //stringstream ss;
    //ss << "G" << groups.GetCurrentGeneratedGroupId(); //轉換成GID 作為map的Key值
    //Group* newGroup = new Group(groups.GetCurrentGeneratedGroupId(),name,members);
    //groups.AddGroup(ss.str(),newGroup);
    //groups.AddGroupID();
}

//取得想要的Group
Group* GMS::FindGroupByGroupId(int groupId){
    return groups.GetGroup(groupId);

}
//加入members ID到Group
void GMS::AddMembersToGroup(int groupId, vector<int> members){
    //使用Command加入Members到指定的Group
    AddMembersToGroupCommand* addMembersCmd = new AddMembersToGroupCommand(&groups,groupId,members);
    cmdManager.execute(addMembersCmd);
    //groups.AddMembersToGroup(groupId,members);
}
bool GMS::Redo(){
   return cmdManager.redo();
}
bool GMS::Undo(){
   return cmdManager.undo();
}
