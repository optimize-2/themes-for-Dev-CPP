# include <bits/stdc++.h>
# include <windows.h>
# include <conio.h>
# include <io.h>
using namespace std;


vector<string>files;
string themefilename[100010];// = {"Intellij-Dark", "Intellij-Light", "Monokai", "One-Dark-Pro", "Pink", "Sakura", "VSCode-Default"};

string getuser() {
	char currentUser[256] ={0};
	DWORD dwSize_currentUser = 256;
	GetUserName(
		currentUser,
		&dwSize_currentUser
		);
	
	string res = currentUser;
	return res;
}

void install_themes() {
	
	Sleep(1000);
	string s = "c:\\Users\\" + getuser() + "\\AppData\\Roaming\\Dev-Cpp\\";
	system("cls");
	system("@echo off");
	puts("info");
	cout << " - 获取到 Dev-C++ AppData 路径" << s << "\n" << "\n"; 
	Sleep(1000);
	/*
	for (register int i = 0; i < files.size(); i++) {
		//string from = themefilename[i] + ".syntax";
		if(files[i][files[i].size()-1]!='x') continue;
		string from=files[i];
		string to = s + from;
		string op = "copy themes\\" + from + " " + to;
		cout << op << "\n";
		system(op.c_str());
		cout << " - 已安装主题 " << from << "\n";
		Sleep(1000);
	}
	system("cls");
	*/
	system(("xcopy themes\\*.syntax "+s).c_str());
	system("cls");
	puts("成功安装全部主题，请回到主页选[2]查看使用/配色提示");
	MessageBox(NULL, "成功安装全部主题", "Dev-C++主题一键安装工具", MB_OK);
	return;
}

void show_theme_tips() {
	system("cls");
	/*
	puts("主题使用提示：");
	puts("  1.打开 Dev-C++");
	puts("  2.选择工具[T] - 编辑器选项[E]");
	puts("  3.切换到语法");
	puts("  4.在最下方选择预设，下拉选取你喜欢的主题即可"); 
	puts("");
	puts("当前行颜色及字体建议：");
	printf("  Intellij Dark : 字体建议使用Jetbarins Mono,当前行建议使用R 50,G 50,B 50.\n"
		"  Intellij Light : 字体建议使用Jetbrains Mono,当前行建议使用R 252,G 250,B 237.\n"
		"  Monokai: 字体建议使用Consolas,当前行建议使用R 56,G 53,B 57.\n"
		"  Pink : 无建议.\n"
		"  Sakura : 无建议.\n"
		"  VScode default : 字体建议使用Consolas,当前行建议取消高亮.\n"
		"  OneDarkPro : 字体建议使用Consolas,当前行建议R 44,G 49,B 60.\n");
	puts("");
	printf("按回车[Enter]返回");
	*/
	system("start README.md");
	getchar(); getchar(); 
} 

void install_fonts() {
	system("cls");
	puts("接下来将会弹出 2个窗口，一个是本工具自带的 .ttf 字体文件夹，另一个是 Windows 字体文件夹，你需要将本工具中的所有 .ttf 字体文件全选，拖动到 Windows 字体文件夹中，并等待系统自动安装完成");
	printf("\n阅读完成后，按回车[Enter]打开窗口");
	getchar(); getchar();
	printf("\n正在打开本工具自带的 .ttf 字体文件");
	system("explorer Fonts");
	printf("\n\n按回车[Enter]打开 Windows 字体文件夹");
	getchar();
	system("start explorer C:\\Windows\\Fonts");
	printf("\n\n按回车[Enter]返回");
	getchar();
	return;
}

void menu() {
	system("title Dev-C++主题一键安装工具"); 
	system("cls");
	puts("");
	puts("               Dev-C++主题一键安装工具");
	puts("    工具作者:Baoyh&optimize_2  主题整理:optimize_2");
	puts(""); 
	puts(" [1] 安装全部主题到工具获取的 Dev-C++ Appdata路径");
	puts(" [2] 查看帮助");
	puts(" [3] 安装全部字体到 Windows\\Font 路径");
	puts(" [4] 打开主题 github 开源地址");
	puts(" [5] 退出工具"); 
	puts("");
	printf(" 请输入操作: "); 
	int x;
	scanf("%d", &x);
	if (x != 1 && x != 2 && x != 3 && x != 4 && x != 5) {
		MessageBox(NULL, "操作输入错误", "Dev-C++主题一键安装工具", MB_OK);
		menu(); 
	} 
	if (x == 5) {
		exit(0);
	}
	if (x == 4) {
		system("start themes\\github.url");
		menu();
	}
	if (x == 1) {
		install_themes();
		menu();
	} 
	if (x == 2) {
		show_theme_tips();
		menu();
	}
	if (x == 3) {
		install_fonts();
		menu();
	}
}

int main() {
	menu();
	return 0;
}
