#include "gms.h"


GMS::GMS()
{
    isWorking = true;
    this->componentID = 1;
    this->groupID = 1;
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

//把components存入檔案
//尚未加入Group....
int GMS::SaveXMLFormatRecord(string path){
    return xmlManager.SaveXML(path,components);
}
int GMS::LoadXMLFormatRecord(string path){
    components.ClearComponents(); //清除原先的Components

    //尚未加入Group...
    int code = xmlManager.LoadXML(path,&components);


    //設定Component現在的最大ID,從載入的XML資料中去看
    //如果有資料,取得檔案中最大的ID,並加一為現在的ID
    if(components.GetComponts().size() >0){
        componentID = components.GetComponts()[components.GetComponts().size()-1]->GetID() +1;
    }

    return code;
}

void GMS::AddComponents(int id, string componentType, string componentName){
    components.AddComponentToList(id,componentType,componentName);

}
//刪除Component與判斷有無存在
bool GMS::DeleteComponent(int id){
    if(this->components.CheckIDHasBeenExisted(id)){
        this->components.DeleteComponentFromList(id);
        return true; //告知有刪除掉
    }
    return false; //沒有刪除掉 因為不存在
}

vector<Component*> GMS::GetComponents(){
    return this->components.GetComponts();
}
//取得目前生產的ComponentsID
int GMS::GetCurrentComponentMakerID(){
    return this->componentID;
}
//取得目前生產的GroupID
int GMS::GetCurrentGroupMakerID(){
    return this->groupID;
}
void GMS::AddComponentID(){
    componentID++;
}

void GMS::AddGroupID(){
    groupID++;
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
void GMS::AddNewGroup(int groupId, string name, vector<int> members){
    Group* newGroup = new Group(groupId,name,members);
    groups.AddGroup(newGroup);
}
