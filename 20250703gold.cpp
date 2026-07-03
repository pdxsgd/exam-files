// 1. 输入/输出 (Input/Output)
#include <iostream>   // 用于标准输入/输出流 (cin, cout, cerr)
#include <fstream>    // 用于文件输入/输出流
#include <sstream>    // 用于字符串流
#include <iomanip>    // 用于格式化输出 (setprecision, setw等)

// 2. 容器 (Containers)
#include <vector>     // 动态数组
#include <string>     // 字符串
#include <list>       // 双向链表
#include <deque>      // 双端队列
#include <map>        // 有序键值对容器
#include <set>        // 有序唯一元素容器
#include <unordered_map> // 无序哈希表键值对容器
#include <unordered_set> // 无序哈希表唯一元素容器
#include <queue>      // 队列
#include <stack>      // 栈

// 3. 算法 (Algorithms)
#include <algorithm>  // 各种通用算法 (sort, find, for_each等)
#include <numeric>    // 数值操作 (accumulate, partial_sum等)

// 4. 功能 (Functions)
#include <functional> // 函数对象、绑定器 (std::function, std::bind等)

// 5. 数学 (Mathematics)
#include <cmath>      // 常用数学函数 (sqrt, pow, sin, cos等)

// 6. 内存管理 (Memory Management)
#include <memory>     // 智能指针 (shared_ptr, unique_ptr, weak_ptr)

// 7. 异常处理 (Exception Handling)
#include <exception>  // 异常基类
#include <stdexcept>  // 标准异常类 (runtime_error, logic_error等)

// 8. 工具 (Utilities)
#include <utility>    // 实用工具 (std::pair, std::move, std::forward等)
#include <tuple>      // 固定大小的异构元素集合

using namespace std;

//===============================================================
int func1(char x, const vector<int>& scores)
{
    if (x!='A' && x!='B' && x!='C'&&x!='D'&&x!='F')
       return -1;
    int count = 0;
    int minvalue = 0;
    int maxvalue = 0;
    if (x=='A')
    {
        minvalue = 90;
        maxvalue = 100;
    }
    else if (x=='B')
    {
        minvalue = 80;
        maxvalue = 89;
    }
    else if (x=='C')
    {
        minvalue = 70;
        maxvalue = 79;
    }
    else if (x=='D')
    {
        minvalue = 60;
        maxvalue = 69;
    }
    else
    {
        minvalue = 0;
        maxvalue = 59;
    }

    for (auto value: scores)
    {
        if (value>=0 && value<=100)
        {
            if (value>=minvalue && value<=maxvalue)
               ++count;
        }
    }
    return count;
}

//===============================================================
bool isPrime(int num)
{
    if (num == 1)
        return false;

    if ((num == 2) || (num==3))
       return true;

    for (int i=2; i<=(int)sqrt(num)+1; ++i )
    {
        if (num%i == 0)
           return false;
    }
    return true;
}

int func2(int n) 
{
    int count=0;
    if (n<=0)
        return -1;
    int num = 1;
    while (count<n)
    {
        if ((num%2==1) && !isPrime(num))
        {
            ++count;
        }
        num += 2;
    }
    return num-2;
}

//===============================================================
vector<string> func3(char a, char b, char c) 
{
    if ((a==b && b==c)
       ||(a!=b && b!=c && c!=a))
       return {"Draw", "Draw", "Draw"};
    if (a==b && ((c=='R' && a=='S')||(c=='S' && a=='P')||(c=='P'&&a=='R')))
       return {"Lose","Lose","Win"};
    if (a==c && ((b=='R' && a=='S')||(b=='S' && a=='P')||(b=='P'&&a=='R')))
       return {"Lose","Win","Lose"};
    if (b==c && ((a=='R' && b=='S')||(a=='S' && b=='P')||(a=='P'&&b=='R')))
       return {"Win","Lose","Lose"};

    if (a==b && ((c=='S' && a=='R')||(c=='P' && a=='S')||(c=='R'&&a=='P')))
       return {"Win","Win","Lose"};
    if (a==c && ((b=='S' && a=='R')||(b=='P' && a=='S')||(b=='R'&&a=='P')))
       return {"Win","Lose","Win"};
    if (b==c && ((a=='S' && b=='R')||(a=='P' && b=='S')||(a=='R'&&b=='P')))
       return {"Lose","Win","Win"};
}

//===============================================================
int getSumDigit(int num)
{
    int value=0;
    while(num>0)
    {
        value += num%10;
        num /= 10;
    }
    return value;
}

int getHighAddLowbit(int num)
{
    int lowbit = num%10;
    int highbit = 0;
    while(num>0)
    {
        if (num<10)
        {
           highbit = num;
           break;
        }           
        num /=10 ;
    }    
    return highbit+lowbit;
}
int getBitCounts(int num)
{
    int count=0;
    while(num>0)
    {
        ++count;
        num /=10 ;
    }
    return count;
}

bool mycompare(int n1, int n2)
{
    int count1=getBitCounts(n1);
    int count2 = getBitCounts(n2);
    if ( count1 == count2)
        return n1>n2;
    return count1<count2;
}

vector<int> func4(int n, int m) {
    vector<int> result;
    result.clear();
    for (int i=n; i<=m; ++i)
    {
        if (i%getSumDigit(i)==0 && getHighAddLowbit(i)%2 == 1)
           result.push_back(i);
    }
    sort(result.begin(), result.end(), mycompare);
    return result;
}

//===============================================================
vector<int> func5(const vector<int>& v1, const vector<int>& v2)
{
    vector<int> result;
    size_t n = v1.size()>v2.size()?v2.size():v1.size();
    size_t i=0;
    for (i=0;i<n; ++i)
    {
        result.push_back(v1[i]);
        result.push_back(v2[i]);
    }
    if (v1.size()>n)
    {
        while(i<v1.size())
        {
            result.push_back(v1[i++]);
        }
    }
    else if (v2.size()>n)
    {
        while(i<v2.size())
        {
            result.push_back(v2[i++]);
        }
    }
    if (result.size()==0)
    	return result;
    	
    // 删除重复元素
    for(size_t i=result.size()-1; i>0; --i)
    {
        if (result[i] == result[i-1])
        {
            result.erase(result.begin()+i);
        }
    }
    return result;
}

//===============================================================
class Student {
private:
    // TODO 1: 声明合适的数据成员来存储学生的基本信息和成绩
    // 提示: 需要存储学生的姓名和多门课程的成绩。
    string m_name;
    vector<double> m_scores;

public:
    // 构造函数
    // TODO 2: 实现构造函数，用于初始化学生姓名。
    Student(const string& name);

    // 成员函数: 添加一门课程的成绩
    // TODO 3: 实现 add_score 函数，将一个成绩添加到成绩列表中。
    void add_score(double score);

    // 成员函数: 计算平均分
    // TODO 4: 实现 get_average_score 函数，计算并返回所有课程的平均分。
    // 如果没有任何成绩，返回 0.0。
    double get_average_score() const;

    // 成员函数: 获取姓名
    // TODO 5: 实现 get_name 函数，获取学生姓名
    string get_name() const;
};

Student::Student(const string& name):m_scores{}
{
    m_name = name;
}

void Student::add_score(double score)
{
    m_scores.push_back(score);
}

double Student::get_average_score() const
{
    double value=0;
    for(auto x:m_scores)
    {
        value += x;
    }
    if (m_scores.size() == 0)
    	 return -1;
    return value/m_scores.size();
}

string Student::get_name() const
{
    return m_name;
}

void func6(const string name, const vector<double>& scores)
{
    Student s { name };
    for (double d : scores) {
        s.add_score(d);
    }
    cout << s.get_name() << ' ' << s.get_average_score() << endl;
}

//===============================================================
//======CSet类定义====
class CSet {
    // TODO1: 实现加法运算符重载函数
    friend CSet operator+(const CSet& set1, const CSet& set2);

    // TODO2: 实现输出运算符重载函数
    friend ostream& operator<<(ostream& out, const CSet& obj);

private: 
    vector<int> m_set;   // 存放元素的向量
    bool m_sortflag;     // 元素排序规则；true--升序排序，false--降序排序

public:
    CSet(const vector<int>& vec = {}, bool sortFlag = true); // 带默认参数的构造函数
    bool hasValue(int value) const; // 查找值value是否在集合中
    void print() const; // 打印集合中所有元素
};

//=======CSet类实现=====
CSet::CSet(const vector<int>& vec, bool sortFlag) // 带参数的构造函数
{
    m_sortflag = sortFlag;
    m_set.clear();
    for (auto x : vec) {
        if (!hasValue(x)) {
            m_set.push_back(x);
        }
    }
    if (sortFlag)
        sort(m_set.begin(),m_set.end()); 
    else
        sort(m_set.begin(), m_set.end(), greater<int>());
}

// 查找值value是否在集合中
bool CSet::hasValue(int value) const
{
    for (unsigned i = 0; i < m_set.size(); ++i) {
        if (m_set[i] == value)
           return true;
    }
    return false;
}

// 打印集合中所有元素
void CSet::print() const
{
    for (int e : m_set) cout << e << ' ';
    cout << endl;
}

//===========友元函数==============
//==加法运算符重载函数=====
CSet operator+(const CSet& set1, const CSet& set2)
{
    CSet result(set1);
    for (auto x:set2.m_set)
    {
        if (!result.hasValue(x))
        {
            result.m_set.push_back(x);
        }
    }
    if (result.m_sortflag)
       sort(result.m_set.begin(), result.m_set.end());
    else
       sort(result.m_set.begin(), result.m_set.end(),greater<int>());    
    return result;    
}

//===输出运算符重载函数====
ostream& operator<<(ostream& out, const CSet& obj)
{
    out<<"{";
    for (unsigned int i=0; i<obj.m_set.size()-1; ++i)
    {
        out<<obj.m_set[i]<<",";
    }
    out<<obj.m_set[obj.m_set.size()-1];
    out<<"}";
    return out;
}



void func7a(const vector<int>& v1, const vector<int>& v2)
{
    CSet set1(v1), set2(v2, false);
    (set1 + set2).print();
}

void func7b(const vector<int>& v)
{
    CSet set1(v);
    cout << set1 << endl;
}

//==================================================================
const double g_pi = 3.14;    // 定义全局常量
class Circle {
    friend ostream& operator<<(ostream& out, const Circle& circle);
private:
    double m_x, m_y;  // 表示圆心坐标
    double m_r;       // 表示圆半径
public:
    Circle(double x = 0, double y = 0, double r = 1);  // 构造函数  
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getR() const { return m_r; }
    //定义一个计算圆面积的成员函数
    double getArea()const;
};

Circle::Circle(double x, double y, double r) : m_x {x}, m_y {y}, m_r {r}
{
}

ostream& operator<<(ostream& out, const Circle& c)
{
    out << '{' << c.m_x << ", " << c.m_y << ", " << c.m_r << '}';
    return out;
}

double Circle::getArea()const
{
    return g_pi*m_r*m_r;
}

bool circleCmp(const Circle& c1, const Circle& c2)
{
    double R1=c1.getR();
    double R2 = c2.getR();
    // 面积相等的比较
    if (fabs(R1-R2) <= 1e-6)
    {
        double x1=c1.getX();
        double x2 = c2.getX();
        if (fabs(x1-x2)<=1e-6)
            return c1.getY()<c2.getY();
        return x1<x2;
    }
    return R1>R2;
}


vector<Circle> func8(const vector<Circle>& circles)
{
    vector<Circle> vec_res;
    for (size_t i=0; i<circles.size(); ++i)
    {
        bool flag = true;
        double x1,y1,r1;
        x1 = circles[i].getX();
        y1 = circles[i].getY();
        r1 = circles[i].getR();
        for (size_t j=0; j<circles.size(); ++j)
        {
            if (i==j)
               continue;
            double x2,y2,r2;
            x2 = circles[j].getX();
            y2 = circles[j].getY();
            r2 = circles[j].getR();
            double dis = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            if ((fabs(dis-(r1+r2)*(r1+r2)) <= 1e-6) // 相等情况判断
               ||(dis <(r1+r2)*(r1+r2)))   // dis
            {
                flag = false;
                break;
            }        
        }
        if (flag)
           vec_res.push_back(circles[i]);
    }
    // 对圆排序
    sort(vec_res.begin(), vec_res.end(), circleCmp);
    return vec_res;
}

//===============================================================
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& vec)
{
	for (const auto& x: vec)
	{
		 out<<x<<" ";
  }	
  return out;
}


int main(int argc, char* argv[]) {
    try{
        if (argc < 2) {
            cerr << "Usage: " << argv[0] << " <function_name> [<function_arguments>...]" << '\n';
            return 1;
        }

        string func_name { argv[1] };

        if (func_name == "func1" && argc >= 4) {            
            char x { argv[2][0] };
            vector<int> scores;
            for (int i { 3 }; i < argc; ++i) {
                scores.push_back(stoi(argv[i]));
            }
            cout << func1(x, scores) << '\n';
            
        } else if (func_name == "func2" && argc == 3) {
            int n { stoi(argv[2]) };
            cout << func2(n) << '\n';
            
        } else if (func_name == "func3" && argc == 5) {
            char x { argv[2][0] };
            char y { argv[3][0] };
            char z { argv[4][0] };
            auto result { func3(x, y, z) };
            std::copy(result.begin(), result.end(), ostream_iterator<string> {cout, " "}); 
            cout << endl;
            
        } else if (func_name == "func4" && argc == 4) {
            int n { stoi(argv[2]) };
            int m { stoi(argv[3]) };
            auto result { func4(n, m) };
            std::copy(result.begin(), result.end(), ostream_iterator<int> {cout, " "}); 
            cout << endl;
            
        } else if (func_name == "func5" && argc >= 4) {
            int m { stoi(argv[2]) };
            vector<int> v1;
            for (int i { 0 }; i < m; ++i) {
                v1.push_back(stoi(argv[3 + i]));
            }
            int n { stoi(argv[3 + m]) };
            vector<int> v2;
            for (int i { 0 }; i < n; ++i) {
                v2.push_back(stoi(argv[4 + m]));
            }
            auto result { func5(v1, v2) };
            std::copy(result.begin(), result.end(), ostream_iterator<int> {cout, " "}); 
            cout << endl;

        } else if (func_name == "func6" && argc >= 3) {
            string name { argv[2] };
            vector<double> scores;
            for (int i = 3; i < argc; ++i) {
                scores.push_back(stoi(argv[i]));
            }         
            func6(name, scores);
            
        } else if (func_name == "func7a" && argc >= 4) {
            int m { stoi(argv[2]) };
            vector<int> v1;
            for (int i { 0 }; i < m; ++i) {
                v1.push_back(stoi(argv[3 + i]));
            }
            int n { stoi(argv[3 + m]) };
            vector<int> v2;
            for (int i { 0 }; i < n; ++i) {
                v2.push_back(stoi(argv[4 + m]));
            }
            func7a(v1, v2);

        } else if (func_name == "func7b" && argc >= 3) {
            int m { stoi(argv[2]) };
            vector<int> v;
            for (int i { 0 }; i < m; ++i) {
                v.push_back(stoi(argv[3 + i]));
            }
            func7b(v);

        } else if (func_name == "func8" && argc >= 3) {
        
            int m { stoi(argv[2]) };
            vector<Circle> circles;
            for (int i { 0 }; i < m; ++i) {
                double x { stod(argv[2 + i * 3 + 1]) };
                double y { stod(argv[2 + i * 3 + 2]) };
                double r { stod(argv[2 + i * 3 + 3]) };
                Circle c {x, y, r};
                circles.push_back(c);
            }
            auto result { func8(circles) };
            std::copy(result.begin(), result.end(), ostream_iterator<Circle> {cout, " "});
            cout << endl;
        
        } else {  
            cerr << "Invalid function name or arguments" << endl;
            return 1;
        }
    }
    catch(const string& err)
    {
        cerr << err << endl;
    }
    return 0;
}
