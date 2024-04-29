#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// name location avalabile beds..rating..contact..doctor name..price
class hospital{
public:
   string hospitaname,location,docname,contact;
   int avaliablebeds,price;
   float rating;

};
 class patient: public hospital{
 public:
    string patientname;
    int id;
};
void printhospitaldata(vector<hospital>&hospitals){
cout<<"hospital data is :"<<endl;
 for (int i = 0; i < 4; i++) {
  cout<<"the name of hospital is :"<<hospitals[i].hospitaname<<endl;
  cout<<"the location of hospital is :"<<hospitals[i].location<<endl;
  cout<<"the doctor name of hospital is :"<<hospitals[i].docname<<endl;
  cout<<"the contact is :"<<hospitals[i].contact<<endl;

}
}
void printpatientdata(vector<patient>&patients,vector<hospital>&hospitals){
  cout<<"patient data is :"<<endl;
 for (int i = 0; i < 4; i++) {
    cout<<"the name of patient is :"<<patients[i].patientname<<endl;
    cout<<"the name of hospital is is :"<<hospitals[i].hospitaname<<endl;
    cout<<"the id of patient is :"<<patients[i].id<<endl;
    cout<<"the name of patient is :"<<patients[i].patientname<<endl;
    cout<<"the patient contact is :"<<hospitals[i].contact<<endl;
    cout<<"the total price is is :"<<hospitals[i].price<<endl;

 }
}
bool name(hospital&a,hospital&b){
   return a.hospitaname>b.hospitaname;
}
void sortinghospitalsbyname(vector<hospital>&hospitals){
  sort(hospitals.begin(),hospitals.end(),name);
  cout << "SORT BY NAME:"<< endl;

    printhospitaldata(hospitals); //after sorting
}
bool rating(hospital&a,hospital&b){
  return a.rating>b.rating;
}
void Sorthospitalbyrating(vector<hospital> hospitals){ sort(hospitals.begin(),hospitals.end(),rating);
  cout << "SORT BY rating:"<< endl;

    printhospitaldata(hospitals); //after sorting }
    }
bool price(hospital&a,hospital&b){
  return a.price>b.price;
}
void Sorthospitalbyprice(vector<hospital> hospitals){ sort(hospitals.begin(),hospitals.end(),price);
  cout << "SORT BY price:"<< endl;

    printhospitaldata(hospitals); //after sorting }
    }
void printhospitalbycity(string city,vector<hospital>&hospitals){
   cout<<" we will print hospitals in the "<<city<<endl;
     for (int i = 0; i < 4; i++) {
       if (hospitals[i].location!=city)
            continue;
       cout<<"the hosptial is name :"<<hospitals[i].hospitaname<<endl;
       cout<<"the location is:"<<hospitals[i].location<<endl;
       cout<<"the price is :"<<hospitals[i].price<<endl;
       cout<<"the rating is :"<<hospitals[i].rating<<endl;
       cout<<"the doctor name is :"<<hospitals[i].docname<<endl;
       cout<<"the contact is :"<<hospitals[i].contact<<endl;
       cout<<"the avaliable beds is :"<<hospitals[i].avaliablebeds<<endl;
     }

}
bool beds(hospital& A, hospital& B)
{
    return A.avaliablebeds > B.avaliablebeds;
}

// Function to sort the hospital
// data by Bed Available
void SortByBedsAvailable(
    vector<hospital> hospitals)
{
    sort(hospitals.begin(),hospitals.end(),beds);

    cout << "SORT BY Available Beds:"<< endl;

    printhospitaldata(hospitals);
}

// Comparator function to sort the
// hospital data by Bed Price
bool beds_price(hospital& A, hospital& B)
{
    return A.price < B.price;
}

// Function to sort the hospital
// data by Bed Price
void SortByBedsPrice(
    vector<hospital> hospitals)
{
    sort(hospitals.begin(),hospitals.end(),beds_price);

    cout << "SORT BY Available Beds Price:"<< endl;
         printhospitaldata(hospitals);
}
void hospitalmangment( string pname[], int pid[],string pcontact[], int bookingcost[],
                      string hospitalname[], string locations[], int beds[],float ratings[], string hospitalcontact[],
                      string doctorname[], int prices[]){
vector<hospital> hospitals;
hospital h;
for (int i=0;i<4;i++){
  h.hospitaname=hospitalname[i];
  h.avaliablebeds=beds[i];
  h.contact=hospitalcontact[i];
  h.location=locations[i];
  h.rating=ratings[i];
  h.price=prices[i];
  h.docname=doctorname[i];
  hospitals.push_back(h);

}
vector<patient> patients;
patient p;
for (int i=0;i<4;i++){
 p.patientname=pname[i];
 p.id=pid[i];
 p.contact=pcontact[i];
 p.price=bookingcost[i];
 patients.push_back(p);


}
cout<<endl;
printhospitaldata(hospitals);
printpatientdata(patients,hospitals);
Sorthospitalbyprice(hospitals);
sortinghospitalsbyname(hospitals);
Sorthospitalbyrating(hospitals);
printhospitalbycity("egypt",hospitals);
SortByBedsAvailable(hospitals);
SortByBedsPrice(hospitals);

}
int main()
{
      string patient_Name[] = { "P1", "P2", "P3", "P4" };
    int patient_Id[] = { 2, 3, 4, 1 };
    string patient_Contact[]
        = { "234534XXX7", "234576XXX2", "857465XXX9",
            "567657XXX0" };
    int bookingCost[] = { 1000, 1200, 1100, 600 };

    string hospital_Name[] = { "H1", "H2", "H4", "H3" };
    string locations[] = { "Bangalore", "Bangalore",
                           "Mumbai   ", "Prayagraj" };
    int beds[] = { 4, 5, 6, 9 };
    float ratings[] = { 5.2, 4.1, 3.4, 5.9 };
    string hospital_Contact[]
        = { "657534XXX7", "298766XXX2", "324565XXX9",
            "343456XXX4" };
    string doctor_Name[] = { "D1", "D4", "D3", "D2" };
    int prices[] = { 100, 200, 100, 290 };

    // Function Call
    hospitalmangment(
        patient_Name, patient_Id, patient_Contact,
        bookingCost, hospital_Name, locations, beds,
        ratings, hospital_Contact, doctor_Name, prices);

    return 0;
}

