#include<bits/stdc++.h>
using namespace std;

string path,username,theme,ctn,font; 

int main() {
	cout<<":) : Plz tell me the path of your System Disk.\n";
	getline(cin,path);
	system("cls");
	cout<<":P : And what\'s your username?\n";
	getline(cin,username);
	system("cls");
install_theme:
	cout<<":p : Then what themes do U want to install?\n";
	getline(cin,theme);
	system("cls");
	cout<<":l : Checking the file...\n";
	string to=path+"\\Users\\"+username+"\\appdata\\roaming\\dev-cpp\\";
	int res=system(("copy "+theme+".syxtax "+path+theme+".syntax >nul").c_str());
	cout<<("copy "+theme+".syxtax "+to+theme+" >nul")<<endl;
	return 0;
	if(res==0) {
		cout<<":( : I cannot find that theme.\n";
		system("pause");
		system("cls");
		goto install_theme;
	} else {
		system("cls");
		cout<<":D : Install sucessfully!\n";
install_fonts:
		cout<<":l : Do U want to install fonts? (Y/N)\n";
		getline(cin,ctn);
		system("cls");
		if(ctn=="Y") {
scan_fonts:
			cout<<"What fonts do U want to install?\n";
			getline(cin,font);
			string to2=path+"\\windows\\fonts";
			int res2=system(("xcopy "+font+"\\ "+to2+" /e /h /q /y >nul").c_str());
			if(res==0) {
				cout<<":( : I cannot find that fonts.\n";
				system("pause");
				system("cls");
				goto scan_fonts;
			} else {
				system("cls");
				cout<<":D : Install sucessfully!\n";
				cout<<":3 : Bye!";
				exit(0);
			}
		} else if(ctn=="N") {
			cout<<":3 : Bye!";
			exit(0);
		} else {
			cout<<":o : I cannot understand U.\n";
			system("pause");
			system("cls");
			goto install_fonts;
		}
	}
}
