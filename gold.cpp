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

int func1(char x, const vector<int>& scores)
{
    string valid_target = "ABCDF"; //有效等级
    if (valid_target.find(x) == string::npos) return -1; // x不是一个有效等级

    int count = 0; // 初始化计数器
    for (int score : scores) { // 遍历成绩向量中的每一个成绩
        // 根据评分标准判断成绩所属等级
        if (score >= 90 && score <= 100) {
            if (x == 'A') {
                count++;
            }
        } else if (score >= 80 && score <= 89) {
            if (x == 'B') {
                count++;
            }
        } else if (score >= 70 && score <= 79) {
            if (x == 'C') {
                count++;
            }
        } else if (score >= 60 && score <= 69) {
            if (x == 'D') {
                count++;
            }
        } else if (score >= 0 && score <= 59) { // 确保成绩在有效范围内
            if (x == 'F') {
                count++;
            }
        } else { // 无效成绩

        }
        // 对于无效成绩（理论上题目说0-100，但健壮性考虑可以增加else分支处理）
        // else {
        //     // 可以选择忽略，或者打印错误信息
        // }
    }

    return count; // 返回对应等级的人数
}

// 函数：判断一个数是否为质数
bool isPrime(int num) {
    if (num <= 1) {
        return false; // 1及更小的数都不是质数
    }
    if (num == 2) {
        return true; // 2是唯一的偶数质数
    }
    if (num % 2 == 0) {
        return false; // 所有大于2的偶数都不是质数
    }
    // 只检查奇数因子，从3开始，步长为2，到其平方根
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) {
            return false; // 找到因子，不是质数
        }
    }
    return true; // 没有找到因子，是质数
}

// 函数：找出第n个是奇数但不是质数的整数
int func2(int n) {
    if (n <= 0) {
        return -1; // 如果n小于等于0，返回-1
    }

    int count = 0; // 计数器，记录找到的符合条件的数的个数
    int num = 1;   // 从1开始检查整数

    while (true) {
        // 检查是否为奇数
        if (num % 2 != 0) {
            // 检查是否不是质数
            if (!isPrime(num)) {
                count++; // 符合条件，计数加1
                if (count == n) {
                    return num; // 找到第n个，返回该数
                }
            }
        }
        num++; // 检查下一个整数
    }
}

std::vector<std::string> func3(char a, char b, char c) {
    std::vector<char> moves = {a, b, c};
    std::unordered_map<char, int> count;
    
    // 统计各手势出现次数
    for (char m : moves) {
        count[m]++;
    }

    // 平局情况一：所有相同
    if (count.size() == 1) {
        return {"Draw", "Draw", "Draw"};
    }

    // 平局情况二：三种手势都出现
    if (count.size() == 3) {
        return {"Draw", "Draw", "Draw"};
    }

    // 两种手势情况
    // 找出是哪个手势占多数，哪个被克制
    char winMove = 0, loseMove = 0;
    if (count.size() == 2) {
        if (count['R'] == 2 && count['S'] == 1) {
            winMove = 'R'; loseMove = 'S';
        } else if (count['S'] == 2 && count['P'] == 1) {
            winMove = 'S'; loseMove = 'P';
        } else if (count['P'] == 2 && count['R'] == 1) {
            winMove = 'P'; loseMove = 'R';
        } else if (count['S'] == 2 && count['R'] == 1) {
            winMove = 'R'; loseMove = 'S';
        } else if (count['P'] == 2 && count['S'] == 1) {
            winMove = 'S'; loseMove = 'P';
        } else if (count['R'] == 2 && count['P'] == 1) {
            winMove = 'P'; loseMove = 'R';
        } else {
            // 平局：一种赢一种输交叉，无法判断
            return {"Draw", "Draw", "Draw"};
        }
    }

    // 输出结果
    std::vector<std::string> result;
    for (char m : moves) {
        if (m == winMove) {
            result.push_back("Win");
        } else if (m == loseMove) {
            result.push_back("Lose");
        } else {
            result.push_back("Draw");
        }
    }

    return result;
}

// 求整数各位数字之和
int digitSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

// 获取数字的最高位
int firstDigit(int x) {
    while (x >= 10)
        x /= 10;
    return x;
}

// 获取数字的最低位
int lastDigit(int x) {
    return x % 10;
}

// 判断是否满足条件1和条件2
bool isQualified(int x) {
    int sum = digitSum(x);
    if (sum == 0 || x % sum != 0) return false; // 条件1
    int fd = firstDigit(x);
    int ld = lastDigit(x);
    return (fd + ld) % 2 == 1; // 条件2：奇数
}

// 主函数：筛选 + 排序
std::vector<int> func4(int n, int m) {
    std::vector<int> result;

    for (int x = n; x <= m; ++x) {
        if (isQualified(x)) {
            result.push_back(x);
        }
    }

    // 自定义排序规则：
    std::sort(result.begin(), result.end(), [](int a, int b) {
        int len_a = std::to_string(a).length();
        int len_b = std::to_string(b).length();
        if (len_a != len_b)
            return len_a < len_b; // 位数升序
        return a > b; // 同位数按值降序
    });

    return result;
}

std::vector<int> func5(const std::vector<int>& v1, const std::vector<int>& v2)
{
    std::vector<int> merged;
    size_t n = v1.size(), m = v2.size();
    size_t len = std::max(n, m);

    for (size_t i = 0; i < len; ++i) {
        if (i < n) merged.push_back(v1[i]);
        if (i < m) merged.push_back(v2[i]);
    }

    std::vector<int> result;
    for (size_t i = 0; i < merged.size(); ++i) {
        if (i == 0 || merged[i] != merged[i - 1]) {
            result.push_back(merged[i]);
        }
    }

    return result;
}

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

Student::Student(const string& name) : m_name { name }, m_scores(0)
{

}

void Student::add_score(double score)
{
    m_scores.push_back(score);
}

double Student::get_average_score() const
{
    double total = accumulate(m_scores.begin(), m_scores.end(), 0.0);
    if (m_scores.size() == 0) return -1;
    else return total / m_scores.size();
}

string Student::get_name() const
{
    return m_name;
}

//======CSet类定义====
class CSet {
    //加法运算符重载函数
    friend CSet operator+(const CSet& set1, const CSet& set2);

    //输出运算符重载函数
    friend ostream& operator<<(ostream& out, const CSet& obj);

private: 
    vector<int> m_set;   // 存放元素的向量
    bool m_sortflag;     // 元素排序规则；true--升序排序，false--降序排序

public:
    CSet(const vector<int>& vec = {}, bool sortFlag = true); // 带默认参数的构造函数
    bool hasValue(int value) const;
    void print() const;
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

// 成员函数：查找值value是否在集合中
bool CSet::hasValue(int value) const
{
    for (unsigned i = 0; i < m_set.size(); ++i) {
        if (m_set[i] == value)
           return true;
    }
    return false;
}

void CSet::print() const
{
    for (int e : m_set) cout << e << ' ';
    cout << endl;
}

//===========友元函数==============
//==加法运算符重载函数=====
CSet operator+(const CSet& set1, const CSet& set2)
{
    unordered_set<int> us(set1.m_set.begin(), set1.m_set.end());
    for (const auto& e : set2.m_set) us.insert(e);
    vector<int> v(us.begin(), us.end());
    CSet cs(v, set1.m_sortflag);
    return cs;  
}

//===输出运算符重载函数====
ostream& operator<<(ostream& out, const CSet& obj)
{
    out << '{';
    if (obj.m_set.size() == 0) {
        out << '}';
    } else if (obj.m_set.size() == 1) {
        out << obj.m_set[0] << '}';
    } else {
        for (int i = 0; i < obj.m_set.size() - 1; ++i) out << obj.m_set[i] << ',';
        out << obj.m_set[obj.m_set.size() - 1] << '}';
    }
    return out;
}


void func6(const string name, const vector<double>& scores)
{
    Student s { name };
    for (double d : scores) {
        s.add_score(d);
    }
    cout << s.get_name() << ' ' << s.get_average_score() << endl;
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

class Circle {
    friend ostream& operator<<(ostream& out, const Circle& circle);
    friend bool operator<(const Circle& c1, const Circle& c2);
private:
    double m_x, m_y;  // 表示圆心坐标
    double m_r;       // 表示圆半径
public:
    Circle(double x = 0, double y = 0, double r = 1);  // 构造函数  
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getR() const { return m_r; }
};

Circle::Circle(double x, double y, double r) : m_x {x}, m_y {y}, m_r {r}
{
}

ostream& operator<<(ostream& out, const Circle& c)
{
    out << '{' << c.m_x << ", " << c.m_y << ", " << c.m_r << '}';
    return out;
}

bool operator<(const Circle& c1, const Circle& c2)
{
    if (c1.getR() < c2.getR()) return false;
    else if (c1.getR() > c2.getR()) return true;
    else {
        if (c1.getX() < c2.getX()) return true;
        else if (c1.getX() > c2.getX()) return false;
        else {
            if (c1.getY() < c2.getY()) return true;
            else return false;
        }
    }
}

bool separated(const Circle& c1, const Circle& c2)
{
    double rs { c1.getR() + c2.getR() };
    double dx { c1.getX() - c2.getX() };
    double dy { c1.getY() - c2.getY() };
    double d2 { dx * dx + dy * dy };
    if (rs * rs < d2) return true;
    return false;
}

vector<Circle> func8(const vector<Circle>& circles)
{
    vector<Circle> v;
    for (int i { 0 }; i < circles.size(); ++i) {
        bool b { true };
        for (int j { 0 }; j < circles.size(); ++j) {
            if (i != j) {
                if (!separated(circles[i], circles[j])) {
                    b = false;
                    break;
                }
            }
        }
        if (b) v.push_back(circles[i]);
    }
    sort(v.begin(), v.end());
    return v;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& vec)
{
	for (const auto& x: vec)
	{
		 out<<x<<" ";
	}
	return out;
}

//--copy--

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
            //std::copy(result.begin(), result.end(), ostream_iterator<string> {cout, " "}); 
            cout<<result<<endl;
            
        } else if (func_name == "func4" && argc == 4) {
            int n { stoi(argv[2]) };
            int m { stoi(argv[3]) };
            auto result { func4(n, m) };
            //std::copy(result.begin(), result.end(), ostream_iterator<int> {cout, " "}); 
            cout <<result<< endl;
            
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
            //std::copy(result.begin(), result.end(), ostream_iterator<int> {cout, " "}); 
            cout <<result<< endl;

        } else if (func_name == "func6" && argc >= 3) {
            string name { argv[2] };
            vector<double> scores;
            for (int i = 3; i < argc; ++i) {
                scores.push_back(stoi(argv[i]));
            }         
            func6(name, scores);
            
        } else if (func_name == "func7a" && argc >= 4) {
        	  int index = 2;
            int m { stoi(argv[index++]) };
            vector<int> v1;
            for (int i { 0 }; i < m; ++i) {
                v1.push_back(stoi(argv[index++]));
            }
            index++;
            int n { stoi(argv[index++]) };
            vector<int> v2;
            for (int i { 0 }; i < n; ++i) {
                v2.push_back(stoi(argv[index++]));
            }
            func7a(v1, v2);

        } else if (func_name == "func7b" && argc >= 3) {
        	  int index=2;
            int m { stoi(argv[index++]) };
            vector<int> v;
            for (int i { 0 }; i < m; ++i) {
                v.push_back(stoi(argv[index++]));
            }
            func7b(v);

        } else if (func_name == "func8" && argc >= 3) {
            int index=2;
            int m { stoi(argv[index++]) };
            vector<Circle> circles;
            for (int i { 0 }; i < m; ++i) {
                double x { stod(argv[index++]) };
                double y { stod(argv[index++]) };
                double r { stod(argv[index++]) };
                Circle c {x, y, r};
                circles.push_back(c);
            }
            auto result { func8(circles) };
            //std::copy(result.begin(), result.end(), ostream_iterator<Circle> {cout, " "});
            cout <<result<< endl;
        
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

