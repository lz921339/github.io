#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

// 生成随机整数
int generateRandomNumber(int maxNumber) {
    return rand() % maxNumber + 1;
}

// 生成随机运算符
char generateRandomOperator(string operators) {
    int index = rand() % operators.size();
    return operators[index];
}

// 生成表达式
string generateExpression(int maxNumber, string operators, bool withParenthesis, bool withDecimal) {
    string expression;

    // 随机生成第一个数字
    int num1 = generateRandomNumber(maxNumber);
    expression += to_string(num1);

    // 随机生成运算符和数字
    for (int i = 0; i < 3; ++i) {
        char op = generateRandomOperator(operators);
        int num2 = generateRandomNumber(maxNumber);
        expression += " ";
        expression += op;
        expression += " ";
        expression += to_string(num2);
        // 是否加小数点
        if (withDecimal && (rand() % 2 == 0)) {
            expression += "." + to_string(generateRandomNumber(99)); // 生成一个小数点后两位的随机数
        }
        // 是否加括号
        if (withParenthesis && (rand() % 2 == 0)) {
            expression = "(" + expression + ")";
        }
    }



    

    return expression;
}

// 生成题目
void generateQuestions(int numQuestions, int maxNumber, string operators, bool withParenthesis, bool withDecimal) {
    ofstream outfile("questions.txt");

    for (int i = 0; i < numQuestions; ++i) {
        string expression = generateExpression(maxNumber, operators, withParenthesis, withDecimal);
        outfile << expression << " = " << endl;
    }

    outfile.close();
}

int main() {
    srand(time(0)); // 设置随机种子

    int numQuestions=10, maxNumber=20;
    string operators="+-*/";
    bool withParenthesis=true, withDecimal=true;

    // 获取用户输入
    cout << "请输入题目数量: ";
   // cin >> numQuestions;

    cout << "请输入最大数: ";
    //cin >> maxNumber;

    cout << "请输入运算符（+ - * /）: ";
    //cin >> operators;

    cout << "是否加括号（1为是，0为否）: ";
   // cin >> withParenthesis;

    cout << "是否有小数（1为是，0为否）: ";
    //cin >> withDecimal;

    generateQuestions(numQuestions, maxNumber, operators, withParenthesis, withDecimal);

    cout << "题目已生成至文件 questions.txt" << endl;

    return 0;
}

