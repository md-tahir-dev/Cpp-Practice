#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Job
{
private:
    int deadline;
public:
    Job(int deadline)
        :   deadline(deadline)  {}
    void updateDeadLine(int deadline)
    {
        this->deadline=deadline;
    }
    int getdeadLine() const
    {
        return deadline;
    }
};

int main()
{
    Job job1(3);
    Job job2(43);
    Job job3(24);
    Job job4(12);
    Job job5(8);
    Job job6(19);
    Job job7(49);
    Job job8(16);
    Job job9(7);
    Job job10(38);
    vector<pair<int,string>> jobs;
    jobs.push_back({job1.getdeadLine(),"Job 1"});
    jobs.push_back({job2.getdeadLine(),"Job 2"});
    jobs.push_back({job3.getdeadLine(),"Job 3"});
    jobs.push_back({job4.getdeadLine(),"Job 4"});
    jobs.push_back({job5.getdeadLine(),"Job 5"});
    jobs.push_back({job6.getdeadLine(),"Job 6"});
    jobs.push_back({job7.getdeadLine(),"Job 7"});
    jobs.push_back({job8.getdeadLine(),"Job 8"});
    jobs.push_back({job9.getdeadLine(),"Job 9"});
    jobs.push_back({job10.getdeadLine(),"Job 10"});

    sort(begin(jobs),end(jobs));
    cout<<jobs[0].second<<" has earliest and "<<jobs[1].second<<" has second most earliest deadline."<<endl;
    return 0;
}