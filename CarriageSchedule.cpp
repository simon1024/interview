#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
https://blog.csdn.net/qq_34781336/article/details/78880402

车厢排序
一列火车有n个车厢标记为1，2，3，4，5，6…n 
现在因为某些原因，需要调整车厢的相对顺序 
例如需要将车厢顺序调整为2，3，1，4，5，6…n 
由于车厢庞大，且车厢只能停留在铁轨上，所以不能随心所欲的调整相对顺序

现在只能利用两条并行的铁轨对车厢的顺序进行调整 
例如 
原序列为1，2的车厢 
车厢1进入铁轨1停止 
车厢2进入铁轨2，然后再开出 
然后铁轨1上的车厢1再开出 
这样可以使得车厢2调整到车厢1得前面

现在给你一个期望得到的车厢顺序，请你判断该顺序能否通过以上方法调整车厢顺序而得到 
（车厢只能前进无法后退） 
输入格式 
第一行n表示有n个车厢 
第二行有n个数为1~n的排列用空格隔开，表示期望得到的车厢顺序

输出：若可以得到则输出Yes 否则输出No

样例输入1： 
2 
2 1 
样例输出1： 
Yes

样例输入2： 
5 
3 4 1 5 2 
样例输出2： 
Yes

样例输入3： 
5 
3 4 2 1 5 
样例输出3： 
No
 */

bool schedule(const vector<int>& order) {
    int frontIdx = 1;

    queue<int> q;
    for(size_t i = 0; i < order.size(); ++i) {
        if (order[i] == frontIdx) {
            frontIdx++;
            cout << order[i] << endl;
            continue;
        }

        if(order[i] > frontIdx) {
            for(int idx = frontIdx; idx < order[i]; idx++) {
                q.push(idx);
            }
            frontIdx = order[i] + 1;
            cout << order[i] << endl;
            continue;
        }

        if(q.front() == order[i]) {
            cout << order[i] << endl;
            q.pop();
        }else {
            return false;
        }
    }

    return true;
}

int main() {
    int order[] = { 3, 4, 1, 5, 2};
    vector<int> v(order, order+sizeof(order)/sizeof(int));

    bool ret = schedule(v);
    cout << "result:" << ret << endl;
    return 0;
}
