coding-test
======================
list of files:
* doc of test description
* files of input and output
** Problem-2


编码测试题目
本次编程测试的参考答题时间为最长不超过2.5小时，外加0.5小时的讨论。推荐使用C++语言实现，如果使用Java或者Python，请自行将参考接口做相应的修改。
其他要求：被试者必须独立完成，不可以参考其他人算法或实现；必须自己通过逻辑思维和编码来解决问题，其他途径获得的答题结果均视为无效。如果需要查C++语言的库函数，请参考：http://www.cplusplus.com/reference/.
题目一（算法）：字符串窗口
问题描述：给定字符串S和T，在S中找出一个最小窗口，该窗口包含T中的所有字符。要求算法时间复杂度为O(n)。
例如，给定 S = "ADOBECODEBANC"，T = "ABC"，则最小的窗口为"BANC".

参考约束：
1：如果在S中，不存在满足要求的窗口（即S无法cover住T中的所有字符），则返回空字符串“”；
2：如果有多个满足要求的窗口，返回第一个即可。 
实现格式（C++示例，可以自行决定）：
class solution2problem1{
    string minimum_window(string S, string T) {
        //Note: 在这里写你的算法实现  
    }
}
另外，Main函数和测试代码的设计可以自行决定。
题目二（综合）：文件个数估计问题

本题目考察被试者综合解决问题的能力。请仔细阅读问题并编程解决。输入以文件的形式给出，包括两个问题规模（见邮件附件），分值比重为1:2，请分别（或统一）设计程序。输出请严格按照示例的格式，否则扣分。测试结束后，被试者须提交输出文件和源代码。关于通过IO重定向来简化文件处理的技巧，见附录。
补充（2017-06-16）：由于离线测试的特殊性，输出文件也已经通过附件给出，请自行比对输出文件来确定你程序的正确性。
Problem Description
In the company HW, there remains a very very old file transfer tool that is still in use today. While the tool is running, it reassures users by giving status updates on both the percentage of files transferred so far and the number of files transferred so far. The status updates during the process might look like this:
20% |==>-------|     1 files transferred
100%|==========|     5 files transferred
But the percentage isn't precise; it is simply truncated before the decimal point (i.e. floored to the next lowest or equal 1%). That is, both 1.2% and 1.7% would be displayed as 1%.
Some users may want to know the exact total number of files, so you want to modify the tool so that the status updates look like this:
20% |==>-------|     1 out of 5 files transferred
100%|==========|     5 out of 5 files transferred
But you've realized that it may or may not be possible to know the number of files. Given the status updates that the tool displays, either figure out how many files there are, or determine that it can't be done (i.e., there are multiple possible values for the number of files). The status updates are not guaranteed to occur at regular intervals and are not guaranteed to occur whenever a file is transferred.
Input
The first line contains T, the number of test cases. T test cases follow. Each test case consists of one line with an integer N, the number of status updates output by the tool, followed by N lines with the format Pi Ki, where Pi and Ki are integers representing the percentage and number of files transferred at some point in the process. The updates are given listed in chronological order -- that is, both the Pi values and the Ki values are nondecreasing throughout a test case.
Output
For each case, output a line starts with "Case #x: y", where x is the number of the case (starting from 1), and y is either the total number of files, or -1 if that number is ambiguous.
Limits
1 ≤ T ≤ 50.
1 ≤ N ≤ 100.
0 ≤ Pi ≤ 100
Small dataset
0 ≤ Ki ≤ 2000
The answer is guaranteed not to exceed 2000.
Large dataset
0 ≤ Ki ≤ 1015
The answer is guaranteed not to exceed 1015.
Sample
 
Content of sample Input file：
3
2
20 1
100 5
10
25 241
27 262
43 407
44 413
57 536
64 601
67 637
84 789
95 893
96 903
10
0 0
8 2
8 2
17 4
30 7
39 9
69 16
73 17
82 19
91 21

Content of sample Output file(i.e., your program’s output)：
Case #1: 5
Case #2: -1
Case #3: 23


附录：通过重定向到标准IO来简化文件读写

代码写完后，可以通过IO重定向的方法来简化文件读写操作。
MY_PROGRAM <input_file.txt >output_file.txt 

以JAVA为例，代码框架可以这么写：
import java.util.*;
import java.io.*;
public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = in.nextInt(); //Scanner has functions to read ints, longs, strings, chars, etc.
    for (int i = 1; i <= t; ++i) {
      int n = in.nextInt();
      int m = in.nextInt();
      System.out.println("Case #" + i + ": " + (n + m) + " " + (n * m));
    }
  }
}

如果你使用C++，则代码框架如下：
#include <iostream>  
using namespace std; 
int main() {
  int t, n, m;
  cin >> t; 
  for (int i = 1; i <= t; ++i) {
    cin >>n >>m;  //read n and then m.
    cout <<"Case #" <<i <<": " <<(n + m) <<" " <<(n*m) <<endl;
  }
  return 0;
}
