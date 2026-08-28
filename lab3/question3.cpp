#include <iostream>
using namespace std;
void Cal_Bill(int cos_ID, int  unit)
{
    double bill,tax=0, total_bill,rate;
    if(unit<200)
    {
        rate = 1.20;
    }
    else if(unit>=200&&unit<400)
    {
        rate = 1.50;
    }
    else if(unit>=400&&unit<600)
    {
        rate = 1.80;
    }
    else
    {
        rate = 2.00;
    }
    bill=rate*unit;
    if(bill>400)
    {
        tax=(bill/100)*15;
    }    
    total_bill=bill+tax;
    if(total_bill<100)
    {
        total_bill=100;
    }
    cout<<"Customer ID No. : "<<cos_ID<<endl;
    cout<<"unit Consumed : "<<unit<<endl;
    cout<<"Amount Charges @Rs. "<<rate<<" per unit: "<<bill<<endl;
    cout<<"Surcharge Amount: "<<tax<<endl;
    cout<<"Net Amount Paid by the Customer: "<<total_bill<<endl;
}
int main()
{
    int cos_ID, unit;
    cout<<"Enter your id: ";
    cin>>cos_ID;
    cout<<"Enter your unit: ";
    cin>>unit;
    Cal_Bill(cos_ID,unit);
    return 0;
}