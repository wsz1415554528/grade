#include<bits\stdc++.h>
#define MAXSIZE 100
using namespace std;

class student{
private:
    char name[20];
    char sex;
    char proName[20];
    int proNum;
    char className[20];
    char phoneNum[20];
public:
    double socre[20];
    double sumSocre;
    student() {
        
    }
    student getStuInformation(student d,int i) {
        cout << endl << "\t\t«Î ‰»Îµ⁄" << i << "∏ˆ—ß…˙–’√˚£∫";
        cin >> d.name;
        cout << "\t\t«Î ‰»Îµ⁄" << i << "∏ˆ—ß…˙–‘±£¨mŒ™ƒ–£¨wŒ™≈Æ£∫";
        cin >> d.sex;
        cout << "\t\t«Î ‰»Îµ⁄" << i << "∏ˆ—ß…˙À˘≤Œº”µƒœÓƒø√˚≥∆∫Õ±‡∫≈£∫" << endl;
        cout << "\t\tœÓƒø√˚≥∆£∫";
        cin >> d.proName;
        cout << "\t\tœÓƒø±‡∫≈£∫";
        cin >> d.proNum;
        cout << "\t\t«Î ‰»Îµ⁄" << i << "∏ˆ—ß…˙À˘‘⁄∞‡º∂£∫";
        cin >> d.className;
        cout << "\t\t«Î ‰»Îµ⁄" << i << "∏ˆ—ß…˙¡™œµ∑Ω Ω£∫";
        cin >> d.phoneNum;
        return d;
    }
    void showName(student d) {
        cout << d.name;
    }
    void showSocre(student d,int i) {
        cout << d.socre[i];
    }
    void operateSumSocre(student &d,int n) {
        int sum;
        for(int i = 0;i < n;i++) {
            d.sumSocre += d.socre[i];
        }
    }
    void sortPro(student d[],int n) {
        student temp;
        for(int i = 0;i < n;i++) {
            for(int j = i;j < n;j++) {
                if(d[i].proNum >= d[j].proNum) {
                    temp = d[j];
                    d[j] = d[i];
                    d[i] = temp;
                }
            }
        }
    }
    void setStuInformation(student d) {
        cout << "\t\t–’√˚£∫" << d.name << endl;
        cout << "\t\t–‘±£∫" << d.sex << endl;
        cout << "\t\t∞‡º∂£∫" << d.className << endl;
        cout << "\t\t¡™œµ∑Ω Ω" << d.phoneNum << endl;
        cout << "\t\tÀ˘≤Œº”œÓƒø±‡∫≈£∫" << d.proNum << endl;
        cout << "\t\tÀ˘≤Œº”œÓƒø√˚≥∆£∫" << d.proName << endl;
        cout << "\t\tÀ˘µ√◊‹∑÷Œ™£∫" << d.sumSocre << endl;
    }
};

class referee{
private:
    char name[20];
    char sex;
    char phoneNum[20];
public:
    referee() {
        
    }
    referee getRefInformation(referee d,int i) {
        cout << endl << "\t\t«Î ‰»Îµ⁄" << i << "∏ˆ≤√≈––’√˚";
        cin >> d.name;
        cout << "\t\t«Î ‰»Î≤√≈––‘±£∫";
        cin >> d.sex;
        cout << "\t\t«Î ‰»Î≤√≈–¡™œµ∑Ω Ω£∫";
        cin >> d.phoneNum;
        return d;
    }
    void showName(referee d) {
        cout << d.name;
    }
    void setSocre(student &d,referee s,int i) {
        cout << endl << "\tœ÷‘⁄ «\t" ;
        s.showName(s);
        cout << "\t≤√≈–∂‘\t" ;
        d.showName(d);
        cout << "\t—ß…˙Ω¯––∆¿∑÷\t" << endl;
        cout << "\t«Î ‰»Î∏√—ß…˙µƒµ√∑÷£∫";
        cin >> d.socre[i];
    }
};

int main() {
    int n;
    int m;
    student d[MAXSIZE];
    referee s[MAXSIZE];
    cout << "\t\t«Î ‰»Î≤Œ»¸—ß…˙ ˝£∫";
    cin >> n;
    cout << "\t\t«Î ‰»Î≤√≈– ˝£∫";
    cin >> m;
    for(int i = 0;i < n;i++) {
        d[i] = d[i].getStuInformation(d[i],i+1);
    }
    for(int i = 0;i < m;i++) {
        s[i] = s[i].getRefInformation(s[i],i+1);
    }
    for(int i = 0 ;i < n;i++) {
        for(int j = 0; j < m;j++) {
            s[j].setSocre(d[i],s[j],j);
        }
    }
    d[0].sortPro(d,n);
    for(int i = 0;i < n;i++) {
        d[i].operateSumSocre(d[i],m);
    }
    for(int i = 0;i < n;i++) {
        cout << endl << "\tµ⁄" << i+1 << "∏ˆ—ß…˙" << endl;
        d[i].setStuInformation(d[i]); 
        cout << endl;
    }
    return 0;
} 
