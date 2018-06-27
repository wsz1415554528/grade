//
//  main.cpp
//  grade
//
//  Created by s20161104602 on 18/6/25.
//  Copyright © 2018年 s20161104602. All rights reserved.
//


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int UMPIRE=5;
class Result{
public:
    Result(int n,char *p)//编号,姓名
    {
        if(strlen(p)<=0)
            cout << " error" << endl;
        num=n;
        strcpy(name,p);
        score=0;
        memset(judgescore,0,UMPIRE);
    }
    Result()
    {
        num=0;
        name[0]='/0';
        score=0;
        memset(judgescore,0,UMPIRE);
    }
    Result(const Result& rhs)
    {
        num=rhs.num;
        strcpy(name,rhs.name);
        score=rhs.score;
        memcpy(judgescore,rhs.judgescore,UMPIRE);
    }
    void InitResult(int n,char *p)
    {
        if(strlen(p)<=0)
            cout << " error" << endl;
        num=n;
        strcpy(name,p);
        
        score=0;
        memset(judgescore,0,UMPIRE);
    }
    void SetJudgeScore(int *s)
    {
        int ix=0;
        while(ix<UMPIRE)
        {
            judgescore[ix]=s[ix];
            ix++;
        }
    }
    
    int* GetJudgeScore()
    {
        return judgescore;
    }
    int GetScore()
    {
        return score;
    }
    int GetNumber()
    {
        return num;
    }
    void ShowName()
    {
        cout << name;
    }
    int FindHighPos();
    int FindLessPos();
    int FindHigh()
    {
        return judgescore[FindHighPos()];
    }
    int FindLess()
    {
        return judgescore[FindLessPos()];
    }
    void DoCalculatorScore();
    
    friend ostream& operator<<(ostream &out,Result );
    ~Result(){}
private:
    int num; //参赛选手编号
    char name[10];//姓名
    int judgescore[UMPIRE];//裁判打分
    int score;//得分
    
};
ostream& operator<<(ostream &out,Result rhs)
{
    
    out << rhs.GetNumber() << "/t";
    rhs.ShowName();
    out << "/t" << rhs.GetScore() << endl;
    return out;
}
int Result::FindHighPos()
{
    int *pmax=max_element(judgescore,(judgescore+UMPIRE));
    return pmax-judgescore;
}
int Result::FindLessPos()
{
    int *pmin=min_element(judgescore,(judgescore+UMPIRE));
    return pmin-judgescore;
}
void Result::DoCalculatorScore()
{
    int maxpos=FindHighPos();
    int minpos=FindLessPos();
    cout << "maxpos:" <<maxpos << endl;
    cout << "minpos:" <<minpos << endl;
    for(int i=0; i<UMPIRE; i++)
    {
        if((i!=maxpos) && (i!=minpos))
        {
            score+=judgescore[i];
        }
    }
    cout << "总成绩=" << score <<endl;
    
    if(FindHigh()==FindLess())
        score = score/(UMPIRE);
    else
        score = score/(UMPIRE-2);
    
}
bool lessbyscore( Result& l, Result& r)
{
    if(l.GetScore()<r.GetScore())
        return true;
    else
        return false;
}
bool lessbynumber( Result& l, Result& r)
{
    if(l.GetNumber()<r.GetNumber())
        return true;
    else
        return false;
}
int init(Result *&p);
void SortByPlayerNumber();
void SortByPlayerScore();
int init(Result *&p)
{
    cout << "输入参赛选手人数:" << endl;
    int n;
    cin >> n;
    cout << endl;
    
    if(!(p = new Result[n]))
    {
        cout << "error" << endl;
        exit(1);
    }
    Result *pmv=p;
    
    int number;
    char name[10];
    for(int i=0; i<n; i++,pmv++)
    {
        cout << "输入所有参赛选手的编号及姓名:" << endl;
        cin >> number >> name;
        pmv->InitResult(number,name);
        
        cout << "开始对第" << i+1 <<"个参赛选手的成绩的打分"<< endl;
        int tmpix=0;
        int pjudgescore[UMPIRE];
        while(tmpix<UMPIRE)
        {
            cout << "输入第" << (tmpix+1) << "个裁判的打分:";
            cin >> pjudgescore[tmpix++];
            
        }
        cout << "结束对第" << n <<"个参赛选手的成绩的打分"<< endl;
        pmv->SetJudgeScore(pjudgescore);
        pmv->DoCalculatorScore();
        cout << "去掉的最高分是:" << pmv->FindHigh() << "/t去掉最低分是:"
        << pmv->FindLess() << "/t最后的得分是:" << pmv->GetScore() << endl;
        tmpix=0;
    }
    return n;
}
void SortByPlayerNumber(Result *p,int n)
{
    sort(p,p+n,lessbynumber);
}
void SortByPlayerScore (Result *p,int n)
{
    sort(p,p+n,lessbyscore);
}
int main()
{
    Result *r;
    int n=init(r);
    
    cout << "按序号从低到高显示结果如下:" << endl;
    SortByPlayerNumber(r,n);
    for (int i=0; i<n; i++)
    {
        cout << r[i];
    }
    cout <<endl;
    cout << "按得分从低到高显示结果如下:" << endl;
    SortByPlayerScore(r,n);
    for (int i=0; i<n; i++)
    {
        cout << r[i];
    }
    
    return 0;
}
