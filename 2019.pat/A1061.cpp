
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
int main() {
	char str1[80],str2[80],str3[80],str4[80];
	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	char week[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int i=0;
	for(i=0;i<len1&&i<len2;i++){
		if(str1[i]==str2[i] && str1[i]>='A'&&str1[i]<='G'){
			printf("%s",week[str1[i]-'A']);
			break;
		}
	}
 
	for(i++;i<len1&&i<len2;i++){
		if(str1[i]==str2[i]){
			if(str1[i]>='0'&&str1[i]<='9'){
				printf(" %02d:",str1[i]-'0');
				break;
			}else if(str1[i]>='A'&&str1[i]<='N'){
				printf(" %02d:",str1[i]-'A'+10);
				break;
			}
		}
	}
 
	for(int j=0;j<len3&&j<len4;j++){
		if(str3[j]==str4[j]){
			if((str3[j]>='A'&&str3[j]<='Z')||(str3[j]>='a'&&str3[j]<='z'))
			{
				printf("%02d",j);
				break;
			}
		}
	}
 
	return 0;
}
