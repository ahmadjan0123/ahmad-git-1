#include<iostream>
using namespace std;

class Person{ // parent class
	protected:
		string name;
		int age;
		string gender;
	public:
		Person(){ // non-paramitrized constrctor
			name = "Not given";
			age = 0;
			gender = "Not given";
		}
				
		void takePersonData(){ // take data from user
			cout << "\nEnter  name: "; cin >> name;
			cout << "\nEnter age: " ; cin>>age;
			cout << "\nEnter  gender: " ; cin>>gender;
			
		}
		
		void showPersonData(){
			cout << "\nName: " << name;
			cout << "\nAge: " << age;			
			cout << "\nGender: " << gender;
		}	
	
};

class Patient : public Person{
	private:
		int patient_id;
		string disease;
	public:
		int patientid(){
			return  patient_id;
		}
		Patient(){
			patient_id = 0;
			disease = " Not given";
		}
		
	void takePatientRecord(){  // to add patient record
			cout << "\nEnter the pateint Id: " ; cin >> patient_id;
			takePersonData();
			cout << "\nEnter the diease : "; cin>>disease;
			

		}
		void displayPatientRecord(){  // to display patient reocrd
			cout << "\nPatient Id: "<< patient_id;
			showPersonData();
			cout << "\nDisease: "<< disease;			
		}		
};
class Doctor : public Person{
	public:
		int doctor_id;
		string specialization;
	void takeDoctorData(){
		cout << "\nEnter doctor id: "; cin >> doctor_id;
		takePersonData();
		cout << "\nEnter doctor specialization: ";cin>>specialization;
	}
	void showDoctorData(){
		cout << "\nDoctor ID: "<< doctor_id;
		showPersonData();
		cout << "\nspecialization: "<< specialization;
		
	}
	
	
};


class Appointment{
	private:
		int time ;
		string date;
		int p_id;
		int d_id;
	public:
		
		int getTime(){
			return  time;
		}
		string getDate(){
			return 	date ;
		}
		int getP_id(){
			return  p_id;
		}
		int getD_id(){
			return  d_id;
			}
		Appointment(){
			time = 0;
			date = " Not given";
			p_id= 0;
			d_id = 0;
		}
		

	void takeAppointmentDetails(){  // to add patient record
			cout << "\nEnter the pateint Id: " ; cin >> p_id;
			cout << "\nEnter the Doctor Id : "; cin>> d_id;
			cout << "\nEnter the time : "; cin>> time;
			cout << "\nEnter the date : "; cin>> date;
			

		}
	void displayAppointmentRecord(){  // to display patient reocrd
			cout << "\nPatient Id: "<< p_id;
			cout << "\nDoctor Id :"<< d_id;			
			cout << "\nTime 	 :"<< time;						
			cout << "\nDate 	 :"<< date;	
					
		}		
};

class Bill{
	public:
		int p_id,d_id;
		float medicine_charges, doctor_fees, room_charges,total;
		Bill(){
			p_id=0;
			d_id=0;
			medicine_charges = 0;
			doctor_fees=0;
			room_charges=0;
		}
		
		void TakeBillRecord(){
			cout << "\nEnter Patient Id: " ; cin >> p_id;
			cout << "\nEnter Doctor Id: " ; cin >> d_id;
			cout << "\nEnter medicine_charges: " ; cin >> medicine_charges;
			cout << "\nEnter doctor_fees: " ; cin >> doctor_fees;
			cout << "\nEnter room_charges: " ; cin >> room_charges;
		}
		void ShowBillRecord(){
			cout << "\nPatient Id: " <<p_id;
			cout << "\nDoctor Id: " << d_id;
			cout << "\nmedicine_charges: " << medicine_charges;
			cout << "\ndoctor_fees: " << doctor_fees;
			cout << "\nroom_charges: " << room_charges;
			
			total = doctor_fees + room_charges+medicine_charges;
			
			cout << "\nTotal :" << total;
		}
};
class hospital{
	private:
		Patient p[100];   // composition
		Doctor d[100]; // composition
		Appointment a[100];
		Bill b[100];
		
		int pcount = 0,dcount = 0,acount=0,bcount=0;;
		
	public:
		// perform crud for the patient
		
		void addpatientRecord(){
			p[pcount].takePatientRecord();
			pcount++;
			cout << "record added succesfully";
		}
		void searchPateint(){   // searching for patients record
			int search_id;
			bool found = false;
			cout << "\nEnter the id: "; cin>>search_id;
			for (int i=0;i<pcount;i++){
				if (p[i].patientid() == search_id){
					cout << "Record found succesfully";
					cout << "\n";
					p[i].displayPatientRecord();
					found = true;
					break;
					cout << "\n";
				}
				
			} if(!found)cout << "\nNot found";
		}
		
		void updatePatientRecord(){
		int id;
		bool found =  false;
		cout << "\nEnter the id: "; cin>>id;
		for (int i=0;i<pcount;i++){
			if (p[i].patientid() == id){
				p[i].takePatientRecord();
				cout << "\nRecord updated sucessfully";
				found = true;
				break;
			}
			
		} if (!found)cout << "\nRecord not found";
		}
		
		void DisplayPatientsRecord(){
			for (int i=0;i<pcount;i++){
				p[i].displayPatientRecord();
			}
		}
		void DeletePatienntRecord(){
			int id;
			cout << "\nEnter the size: " ;  cin >> id;
			bool found =  false;
			for (int i=0;i<pcount;i++){
				if (p[i].patientid() == id){
					found = true;
						for (int j=i;j<pcount-1;j++){
							p[j] = p[j+1];
						}
						pcount--;
						
				}
				
			} if (!found )cout << "\nRECORD NOT FOUND";
		}
		
		// now we perform CRUD for doctors
		// add update doctors record
		
		void addDoctorRecord(){
			d[dcount].takeDoctorData();
			dcount++;
		}
		void updateDoctorRecord(){
			int id;
			cout << "Enter id: "; cin >> id;
			bool found = false;
			for (int i=0;i<dcount;i++){
				if (d[i].doctor_id == id){
					d[i].takeDoctorData();
					
					cout << "\nUpdated successfully";
					found = true;
					break;
				}
			}
			
			if (!found) cout << "\nRecord Not Found";
		}
		
		void searchDoctorRecord(){
			int id;
			cout << "\nEnter Doctor Id: "; cin >> id;
			bool found = false;
			for (int i=0;i<dcount;i++){
				if (d[i].doctor_id == id){
					cout << "\n\nRecord found: ";
					d[i].showDoctorData();
					found = true;
					break;
				}
				
			}
		   	 if(!found)   cout << "\nRecord Not Found";	
		}
		void deleteDoctorRecord(){
			
			int id;
			cout << "Enter the doctor id: ";  cin >> id;
			bool found = false;
			for (int i=0;i<dcount;i++){
				if (d[i].doctor_id == id){
					found = true;
					for (int j=i;j<dcount-1;j++){
						d[j] = d[j+1];
						
						
					}
					dcount--; 
				}
			
			} if(!found) cout << "NOT FOuND";
		
		}
		void displayDoctors(){
			for (int i=0;i<dcount;i++){
				d[i].showDoctorData();
			}
		}
		
		// now we perform crud for the appointment
		void BookAppointment(){
			a[acount].takeAppointmentDetails();
			acount++;
			
			cout << "\nRecord Added Sucessfully";
		}
		
		void showAppointmentRecord(){
			for(int i=0;i<acount;i++){
				a[i].displayAppointmentRecord();
			}
		}
		
		void SearchAppointmentRecord(){
			int id;
			bool found = false;
			cout << "\nEnter the patient id: "; cin >> id;
			for (int i=0;i<acount;i++){
				if (a[i].getP_id()==id){
					cout << "\nRecord found sucesfully";
					a[i].displayAppointmentRecord();
					found = true;
					break;
				}
			} if(!found) cout << "\nNot found";
	}
		void DeleteAppointmentRecord(){
			int id;
			cout << "\nEnter the patient record: "; cin >> id;
			bool found = false;
			for (int i=0;i<acount;i++){
				if (a[i].getP_id()==id){
					found = true;
					for (int j=i; j<acount-1;j++){
						a[j] = a[j+1];
						
						
						
					}acount--;
				}
			}
		
			if(!found)	cout << "\nRecord not found";
		}
		
		// billing part 
		void createBillRecord(){
			b[bcount].TakeBillRecord();
			bcount++;
			
			cout << "\nBill Generated Sucessfully";
		}
		void searchBillRecord(){
			int id;
			bool found = false;
			cout << "\nEnter the id"; cin >> id;
			for (int i=0;i<bcount;i++){
				if(b[i].p_id==id){
					cout << "\nRecord found succesfully";
					b[i].ShowBillRecord();
					found = true;
					break;
				}
			}
			if(!found)cout << "\nRecord not found";
		}
		void showBillRecords(){
			
			for (int i=0;i<bcount;i++){
				 b[i].ShowBillRecord();
				}
			}
		
		void DeleteBillRecord(){
			int id;
			cout << "\nEnter patient id: "; cin >> id;
			 bool found = false;
			 for (int i=0;i<bcount;i++){
			 	if (b[i].p_id==id){
				 
			 	found = true;
			 	
			 	for (int j=i;j<bcount-1;j++){
			 		b[j] = b[j+2];
			 				
				 } bcount --;
			   }
			}
			 if (!found)cout << "\nRecord not found";
		}
};

int main(){
	hospital h;

int choice;

do {

    cout << "\n1.Patient Management";
    cout << "\n2.Doctor Management";
    cout << "\n3.Appointment Management";
    cout << "\n4.Bill Generation";
    cout << "\n5.Exit";

    cout << "\nEnter choice: ";
    cin >> choice;

    switch(choice) {

    case 1: {

        int p_choice;

        do {

            cout << "\n PATIENT MENU";
            cout << "\n1. Add Record";
            cout << "\n2. Search Record";
            cout << "\n3. Delete Record";
            cout << "\n4. Update Record";
            cout << "\n5. Display Record";
            cout << "\n6. Back";

            cout << "\nEnter choice: ";
            cin >> p_choice;

            switch(p_choice) {

                case 1: h.addpatientRecord(); 
                break;

                case 2: h.searchPateint(); 
                break;

                case 3: h.DeletePatienntRecord(); 
                break;

                case 4: h.updatePatientRecord(); 
                break;

                case 5: h.DisplayPatientsRecord(); 
                break;

                case 6: break;

                default:
                    cout << "\nInvalid";
            }

        } while(p_choice != 6);

        break;
    }

    case 2: {

        int d_choice;

        do {
			cout << "\nDoctor Management ";
            cout << "\n1. Add Record \n2. Delete Record \n3. Update Record \n4. Search Record \n5. Display Record \n6. Back";

            cout << "\nEnter your choice: ";
            cin >> d_choice;

            switch (d_choice) {

                case 1:
                    h.addDoctorRecord();
                    break;

                case 2:
                    h.deleteDoctorRecord();
                    break;

                case 3:
                    h.updateDoctorRecord();
                    break;

                case 4:
                    h.searchDoctorRecord();
                    break;

                case 5:
                    h.displayDoctors();
                    break;

                case 6:
                    break;

                default:
                    cout << "\nInvalid Operation";
            }

        } while (d_choice != 6);
 
        break;
    }

    case 3:
    {
        int a_choice;

        cout << "\nAppointment Management";

        do {

            cout << "\n1. Add Record \n2. Delete Record \n3. Search Record \n4. Display Record \n5. Back to menu";
            cout << "\nEnter your choice: ";
            cin >> a_choice;

            switch (a_choice){

                case 1:
                    h.BookAppointment();
                    break;

                case 2:
                    h.DeleteAppointmentRecord();
                    break;

                case 3:
                    h.SearchAppointmentRecord();
                    break;

                case 4:
                    h.showAppointmentRecord();
                    break;

                case 5:
                    break;

                default:
                    cout << "\nInvalid Operation";
            }

        } while (a_choice != 5);

        break;
    }

    case 4:
        cout << "\nBill Generation";
        int bill_choice;
        do{
        	cout << "\n1. Add Bill \n2. Delete Bill \n3. Update Bill \n4. Search bill";
        	cout << "Enter your choice: "; cin >> bill_choice;
        	
        	switch(bill_choice){
        		case 1:
        			h.createBillRecord();
        			break;
        		case 2:
        			h.DeleteBillRecord();
        			break;
        		case 3:
        			h.showBillRecords();
        			break;
        		case 4:
        			h.searchBillRecord();
        			break;
        		case 5:
        			break;
        		default:
        			cout << "\nInvalid Operation";
			}
		} while (bill_choice !=  5);
        break;

    case 5:
        cout << "\nProgram End";
        break;

    default:
        cout << "\nInvalid Choice";
    }

} while(choice != 5);

return 0;
}
