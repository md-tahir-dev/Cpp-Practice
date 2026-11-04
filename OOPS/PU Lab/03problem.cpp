#include <iostream>
#include <stdexcept>
using namespace std;
class Team
{
private:
    int score;
    int wickets;
public:
    Team()
    {
        score=0;
        wickets=0;
    }
    Team(int score, int wicket)
        : score(score), wickets(wicket){}
    void setScore(int score)
    {   
        if(score<0)
        {
            throw invalid_argument("You entered invalid score.");
        }
        this->score=score;
    }
    void setWicket(int wicket)
    {
        if(wicket<0)
        {
            throw invalid_argument("You entered invalid wickets.");
        }
        this->wickets=wicket;
    }

    void updateTeam(int score, int wickets)
    {
        this->score=score;
        this->wickets=wickets;
    }
    int getScore() const
    {
        return score;
    }
    int getWicket() const
    {
        return wickets;
    }
};
int main()
{
    Team Team1;
    int score1;
    int wicket1;
    Team Team2;
    int score2;
    int wicket2;
    cout<<"****Enter data for Team1****"<<endl;
    cout<<"\nEnter score: ";
    cin>>score1;
    Team1.setScore(score1);
    cout<<"\nEnter the number of wickets: ";
    cin>>wicket1;
    Team1.setWicket(wicket1);
    cout<<"\nTeam 1 has score: "<<Team1.getScore()<<" and number of wickets: "<<Team1.getWicket()<<endl;
    cout<<"\n****Enter data for Team2****"<<endl;
    cout<<"\nEnter score: ";
    cin>>score2;
    Team2.setScore(score2);
    cout<<"\nEnter the number of wickets: ";
    cin>>wicket2;
    Team2.setWicket(wicket2);
    cout<<"\nTeam 2 has score: "<<Team2.getScore()<<" and number of wickets: "<<Team2.getWicket()<<endl;

    // (b) task
    
    Team Team3;
    Team Team4(11, 2);
    Team3.setWicket(10);
    cout<<"\n**** Team3 created (default)****";
    cout<<"\nTeam 3 has score: "<<Team3.getScore()<<" and number of wickets: "<<Team3.getWicket()<<endl;
    cout<<"\n**** Team4 created (parameterized)****";
    cout<<"\nTeam 4 has a score: "<<Team4.getScore()<<" and number of wickets: "<<Team4.getWicket()<<endl;

    // (c) tasks
    int maxscore=Team1.getScore();
    int minscore=Team1.getScore();

    string maxTeam= "Team 1";
    string minTeam= "Team 1";

    if(Team2.getScore()>maxscore)
    {
        maxscore=Team2.getScore();
        maxTeam="Team 2";
    }
    if(Team3.getScore()>maxscore)
    {
        maxscore=Team3.getScore();
        maxTeam="Team 3";
    }
    if(Team4.getScore()>maxscore)
    {
        maxscore=Team4.getScore();
        maxTeam="Team 4";
    }

    if(Team2.getScore()<minscore)
    {
        minscore=Team2.getScore();
        minTeam="Team 2";
    }
    if(Team3.getScore()<minscore)
    {
        minscore=Team3.getScore();
        minTeam="Team 3";
    }
    if(Team4.getScore()<minscore)
    {
        minscore=Team4.getScore();
        minTeam="Team 4";
    }

    cout<<"\n"<<maxTeam<<" has a max score.";
    cout<<"\n"<<minTeam<<" has a min score.";

    cout<<"\nTeams with greater than 6 wickets: ";
    if(Team1.getWicket()>6)
    {
        cout<<"Team 1 ";
    }
    if(Team2.getWicket()>6)
    {
        cout<<"Team 2 ";
    }
    if(Team3.getWicket()>6)
    {
        cout<<"Team 3 ";
    }
    if(Team4.getWicket()>6)
    {
        cout<<"Team 4 ";
    }
    return 0;
}