//
// Created by SolarDomo on 2021/4/18.
//

#include "common.h"

struct task {
    int index, enqueue_time, cost;
    void print() const {
        cout << index << " " << enqueue_time << " " << cost << endl;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> result;

        auto compare_for_pq = [](const task& t1, const task& t2) {
            return !(t1.cost < t2.cost || (t1.cost == t2.cost && t1.index < t2.index));
        };
        priority_queue<task, vector<task>, decltype(compare_for_pq)> pq(compare_for_pq);
        auto push_queue = [&](const vector<task>& tasks) {
            for (const auto &item : tasks) pq.push(item);
        };
        map<int, vector<task>> m_task;
        for (int i = 0; i < tasks.size(); ++i)
            m_task[tasks[i][0]].push_back(task{i, tasks[i][0], tasks[i][1]});
        int prev_time = 0;
        task prev_task{-1,-1,-1};
        for (const auto& m_iter : m_task) {
            if (prev_time == 0) {
                prev_time = m_iter.first;
                push_queue(m_iter.second);
                prev_task = pq.top();pq.pop();
            } else {
                int cur_time = m_iter.first;
                int time_interval = cur_time - prev_time;
                while (prev_task.cost < time_interval) {
                    time_interval -= prev_task.cost;
                    result.push_back(prev_task.index);
                    if (!pq.empty()) {
                        prev_task = pq.top();pq.pop();
                    } else {
                        prev_task = {-1,-1,-1};
                        break;
                    }
                }
                push_queue(m_iter.second);
                if (prev_task.index != -1) {
                    prev_task.cost -= time_interval;
                    if (prev_task.cost == 0) {
                        result.push_back(prev_task.index);
                        prev_task = pq.top();pq.pop();
                    }
                } else {
                    prev_task = pq.top();pq.pop();
                }
                prev_time = cur_time;
            }
        }
        if (prev_task.index != -1) result.push_back(prev_task.index);
        while(!pq.empty()) {
            auto t = pq.top(); pq.pop();
            result.push_back(t.index);
        }
        return result;
    }
};

int main() {
    vector<vector<int>> in {
            {1,2}, {2,4}, {3,2}, {4,1}
    };
    vector<vector<int>> in2 {
            {7, 10},
            {7, 12},
            {7, 5},
            {7, 4},
            {7, 2},
    };
    Solution s;
    auto res = s.getOrder(in);
    for (const auto &item : res) cout << item << endl;
}