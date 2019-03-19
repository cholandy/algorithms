#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

class p {
public:
	char t;
	int c, h, o;
	p(int a, int b, int c, char t)
		:c(a),h(b),o(c),t(t)
	{}
};

int main() {
	char s[101];
	scanf("%s",s);
	int l=strlen(s);
	int c=0, h=0, o=0;
	vector<p> st;
	for(int i=0;i<l;i++) {
		if(s[i]=='(') st.push_back(p(0,0,0,'('));
		else if(s[i]=='C') st.push_back(p(1,0,0,'X'));
		else if(s[i]=='H') st.push_back(p(0,1,0,'X'));
		else if(s[i]=='O') st.push_back(p(0,0,1,'X'));
		else if(s[i]==')') {
			int C=0, H=0, O=0;
			while(st[st.size()-1].t!='(') {
				C+=st[st.size()-1].c;
				H+=st[st.size()-1].h;
				O+=st[st.size()-1].o;
				st.pop_back();
			}
			st.pop_back();
			st.push_back(p(C,H,O,'X'));
		} else {
			int iter=s[i]-'0';
			p temp(st[st.size()-1].c*iter,st[st.size()-1].h*iter,st[st.size()-1].o*iter,'X');
			st.pop_back();
			st.push_back(temp);
		}
	}
	for(int i=0;i<st.size();i++) {
		c+=st[i].c;
		h+=st[i].h;
		o+=st[i].o;
	}
	printf("%d",c*12+o*16+h);
}