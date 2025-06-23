//#include "httplib.h"
//#include "json.hpp"
#include <iostream>

using namespace std;
//using namespace httplib;
//using namespace nlohmann;

void login();
void sign_up();
void login_menu();
void home_menu();     
void me_menu();        
void logout();
void check_me();
void update_me();
void delete_me();
void check_my_posts();
void check_my_comments();
void upload_post();
void post_list();
void choose_post();
void write_comment();
void comment_list();
void search_user();
void search_post();
/*
void search_user(string search=""){
    Client cli("127.0.0.1:5000");
    string endpoint = "/users/search";

    json body;
    body["search"] = search;

    auto res = cli.Post(endpoint,body.dump(),"application/json");

    if (res && res->status == 200){
        //cout << res->body << endl;
        json response = json::parse(res->body);
        cout << "status" << response["status"] << endl;
        cout << "user" << response["user"] << endl;
        //cout << res->body << endl;
    }
    else
        cout << res.error() << endl;
}

void delete_me(int user_id){
    Client cli("127.0.0.1:5000");

    string endpoint = "/users/" + to_string(user_id);

    auto res = cli.Delete(endpoint);

    if (res && res->status == 200){
        cout << res->body << endl;
    }
    else
        cout << res.error() << endl;
}

int main() {
    //delete_me(7);
    search_user();
    return 0;
}
    */
string user_input;

void login(){
    cout << "�α��� �Ϸ�" << endl << endl;
}
void sign_up(){
    cout <<"ȸ������ �Ϸ�" << endl << endl;
}
void login_menu(){
    user_input = "";
    while(1){
        cout << "[�α��� �޴�]" << endl;
        cout << "| �α��� | ȸ������ |" << endl << endl;;
        cout << "�̿��� ���񽺸� �Է��ϼ���. : ";
        getline(cin, user_input);
        cout << endl;

        if(user_input == "�α���"){
            login();
            home_menu();
            if(user_input == "����"){
                break;
            }
        }
        else if(user_input == "ȸ������"){
            sign_up();
        }
    }   
}
void me_menu(){
    user_input = "";
    while(1){
        cout << "[�� ���� �޴�]" << endl;
        cout << "| ����� ���� ��ȸ | ����� ���� ���� | ����� ���� | ���� �� ����Ʈ ���� | ���� �� ��� ���� | �ڷΰ��� |" << endl;
        cout << "�̿��� ���񽺸� �Է��ϼ���. : ";
        getline(cin, user_input);
        cout << endl;

        if(user_input == "����� ���� ��ȸ"){
            check_me();
        }
        else if(user_input == "����� ���� ����"){
            update_me();
        }
        else if(user_input == "����� ����"){
            delete_me();
            break;
        }
        else if(user_input == "���� �� ����Ʈ ����"){
            check_my_posts();
        }
        else if(user_input == "���� �� ��� ����"){
            check_my_comments();
        }
        else if(user_input == "�ڷΰ���"){
            return;
        }
    }
}
void choosing_post_menu(){
    user_input = "";
        while(1){
            post_list();
            cout << "| ����Ʈ ���뺸�� | �ڷΰ��� |" << endl;
            cout << "�̿��� ���񽺸� �Է��ϼ���. : ";
            getline(cin, user_input);
            cout << endl;

            if(user_input == "����Ʈ ���뺸��"){
                choose_post();
                while(1){
                    cout << "| ����Է� | �ڷΰ���|" << endl;
                    cout << "�̿��� ���񽺸� �Է��ϼ���. : ";
                    getline(cin, user_input);
                    cout << endl;
                    if(user_input == "����Է�"){
                        write_comment();
                    }
                    else if(user_input == "�ڷΰ���"){
                        return;
                    }
                }
            }
            if(user_input == "�ڷΰ���")
                return;
        }

}
void posting_menu(){
    user_input="";
    while(1){
        cout << "[������ �޴�]" << endl;
        cout << "| ����Ʈ �ۼ� | ����Ʈ ��� ��ȸ | �ڷΰ��� |" << endl;
        cout << "�̿��� ���񽺸� �Է��ϼ���. : ";
        getline(cin, user_input);
        cout << endl;

        if(user_input == "����Ʈ �ۼ�"){
            upload_post();
        }
        else if(user_input == "����Ʈ ��� ��ȸ"){
            choosing_post_menu();
        }
        else if(user_input == "�ڷΰ���"){
            return;
        }
    }
}
void search_menu(){
    user_input="";
    while(1){
        cout << "[�˻� �޴�]" << endl;
        cout << "| �ٸ� ����� �˻� | ����Ʈ �˻� | �ڷΰ��� |" << endl;
        cout << "�̿��� ���񽺸� �Է��ϼ���. : ";
        getline(cin, user_input);
        cout << endl;

        if(user_input == "�ٸ� ����� �˻�"){
            search_user();
        }
        else if(user_input == "����Ʈ �˻�"){
            search_post();
        }
        else if(user_input == "�ڷΰ���"){
            return;
        }
    }
}
void home_menu(){
    user_input="";
    while(1){
        cout << "[���θ޴�]" << endl;
        cout << "| �� ���� | ������ | Ž�� | �α׾ƿ� | ���� |" << endl;
        cout << "�̿��� ���񽺸� �Է��ϼ���. : ";
        getline(cin, user_input);
        cout << endl;

        if(user_input == "�� ����"){
            me_menu();
            if(user_input == "����� ����"){
                break;
            }
        }
        else if(user_input == "������"){
            posting_menu();
        }
        else if(user_input == "Ž��"){
            search_menu();
        }
        else if(user_input == "�α׾ƿ�"){
            logout();
            break;
        }
        else if(user_input == "����"){
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }
    }
}
void logout(){
    cout << "�α׾ƿ��� �Ϸ�Ǿ����ϴ�." << endl << endl;
}
void check_me(){
    cout << "[����� ���� ��ȸ]" << endl;
    cout << "�̸� : ȫ�浿" << endl;
    cout << "���� : 30��" << endl << endl;
}
void update_me(){
    cout << "[����� ���� ����]" << endl;
    cout << "���� ���� �Ϸ�" << endl << endl;
}
void delete_me(){
    cout << "[����� ����]" << endl;
    cout << "����� ���� �Ϸ�" << endl << endl;
}
void check_my_posts(){
    cout << "[���� �� ����Ʈ ����]" << endl;
    cout << "���� �� ����Ʈ ��ϵ�" << endl << endl;
}
void check_my_comments(){
    cout << "[���� �� ��� ����]" << endl;
    cout << "���� �� ��� ��ϵ�" << endl << endl;
}
void upload_post(){
    cout << "[����Ʈ �ۼ�]" << endl;
    cout << "����Ʈ �ۼ� �Ϸ�" << endl << endl;
}
void post_list(){
    cout << "[����Ʈ ��� ��ȸ]" << endl;
    cout << "����Ʈ1\n����Ʈ2\n����Ʈ3" << endl << endl;
}
void choose_post(){
    char yn = 'n';
    cout << "������ �� ����Ʈ�� �Է��ϼ��� : ";
    getline(cin, user_input);
    cout <<user_input << "�� ����" << endl;
    comment_list();
}
void comment_list(){
    cout << "��� ��ϵ� ��ȸ �Ϸ�" << endl << endl;
}
void write_comment(){
    cout << "��� �Է¿Ϸ�" << endl << endl;
}
void search_user(){
    cout << "�˻��� ���� ��� ��ȸ �Ϸ�" << endl << endl;
}
void search_post(){
    cout << "�˻��� ����Ʈ ��� ��ȸ �Ϸ�" << endl << endl;
}


int main(){
    login_menu();

    return 0;
}