#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class jewellery_mgmt{
	public:
		int jewel_id;
		char jewel_type[26];//diamond,gold,platinum
		char jewel_manufacture_date[26];
		int jewel_count;
		int jewel_price;
		char jewel_company[26];
		char jewel_return_allowed[26];// yes or no
		char jewel_category[26];//ring,necklace,bangles
		
	void get(){
	            while(1){
				cout<<"ID = "<<jewel_id<<endl;
			    cout<<"TYPE = "<<jewel_type<<endl;
			    cout<<"MANUFACTURE DATE = "<<jewel_manufacture_date<<endl;
			    cout<<"COUNT = "<<jewel_count<<endl;
			    cout<<"PRICE = "<<jewel_price<<endl;
			    cout<<"COMPANY = "<<jewel_company<<endl;
			    cout<<"RETURN ALLOWED = "<<jewel_return_allowed<<endl;
			    cout<<"CATEGORY = "<<jewel_category<<endl;
			    cout<<endl;
			    cout<<"------------------------------------------"<<endl<<endl; 
				break; 
	         	}
        	}
};

fstream fp;
jewellery_mgmt st;

void first(){
	fp.open("project.txt",ios::out | ios::app );
	char ch='y';
	while(ch=='y'){
	cout<<"Enter jewel_id : ";
	cin>>st.jewel_id;
	cout<<"Enter jewellery type : ";
	cin>>st.jewel_type;
    cout<<"Enter jewellery manufacture date : ";
	cin>>st.jewel_manufacture_date;
    cout<<"Enter jewellery count : ";
	cin>>st.jewel_count;
	cout<<"Enter jewellery price : ";
	cin>>st.jewel_price;
	cout<<"Enter jewellery company : ";
	cin>>st.jewel_company;
	cout<<"Enter jewellery return allowed (y/n) : ";
	cin>>st.jewel_return_allowed;
	cout<<"Enter jewellery category : ";
	cin>>st.jewel_category;
	fp.write((char*)&st,sizeof(st));
	cout<<"Do you want to continue (y/n) : ";
	cin>>ch;
}
	fp.close();
}

void second(){
	fp.open("project.txt",ios::in );
	cout<<"*****DETAILS OF JEWELLERY*****"<<endl<<endl;
    if(!fp){
    	cout<<"File not found";
	}
	else{
		while(fp.read((char*)&st,sizeof(st))){
			cout<<"ID = "<<st.jewel_id<<endl;
			cout<<"TYPE = "<<st.jewel_type<<endl;
			cout<<"MANUFACTURE DATE = "<<st.jewel_manufacture_date<<endl;
			cout<<"COUNT = "<<st.jewel_count<<endl;
			cout<<"PRICE = "<<st.jewel_price<<endl;
			cout<<"COMPANY = "<<st.jewel_company<<endl;
			cout<<"RETURN ALLOWED = "<<st.jewel_return_allowed<<endl;
			cout<<"CATEGORY = "<<st.jewel_category<<endl;
			cout<<endl;
			cout<<"------------------------------------------"<<endl<<endl;          
		}
		fp.close();
	}
}
  
void third(){
	fp.open("project.txt",ios::in);
	char type1[20]="gold";
	char type2[20]="platinum";
	while(fp.read((char*)&st,sizeof(st))){
		if(strcmp(st.jewel_type,type1)==0 || strcmp(st.jewel_type,type2)==0  ){
			st.get();
		}
	}
}

void fourth(){
	fp.open("project.txt",ios::in);
	char ret[20]="yes";
	while(fp.read((char*)&st,sizeof(st))){
		if(strcmp(st.jewel_return_allowed,ret)==0){
			st.get();
	}
}
}

void fifth(){
	fp.open("project.txt",ios::in);
	char comp[20]="S&S";
	while(fp.read((char*)&st,sizeof(st))){
		if(strcmp(st.jewel_company,comp)==0){
		st.get();
		}
	}
}

void sixth(){
	fp.open("project.txt",ios::in);
	char comp[20]="S&S";
	while(fp.read((char*)&st,sizeof(st))){
		if(st.jewel_count<10){
		st.get();
		}
	}
}

void seventh(){
	fp.open("project.txt",ios::in);
	char comp1[20]="DDmas";
    char comp2[20]="Aura";	
	while(fp.read((char*)&st,sizeof(st))){
		if(strcmp(st.jewel_company,comp1)==0 || strcmp(st.jewel_company,comp2)==0){
		st.get();
		}
	}
}

void eighth(){
	fp.open("project.txt",ios::in);	
	while(fp.read((char*)&st,sizeof(st))){
		if(st.jewel_price>5000 && st.jewel_price<15000){
		st.get();
		}
	}
}

void ninth(){
	fp.open("project.txt",ios::in);	
	char cat[20]="necklace";
	while(fp.read((char*)&st,sizeof(st))){
		if(strcmp(st.jewel_category,cat)==0 && st.jewel_price<10000){
		st.get();
		}
	}
}

void tenth(){
	fp.open("project.txt",ios::in);	
	char cat[20]="diamond";
	while(fp.read((char*)&st,sizeof(st))){
		if(strcmp(st.jewel_type,cat)==0 && st.jewel_price>20000){
		st.get();
		}
	}
}
int main()
{
	int choice;
	while(1){
	cout<<"====================================================================================="<<endl;
    cout<<"\t\t\t\t\t MENU "<<endl;
    cout<<"====================================================================================="<<endl<<endl;
	cout<<"1. Add Data"<<endl;
	cout<<"2. Display all data"<<endl;
	cout<<"3. Display all the jewellery items which are of either gold or platinum ."<<endl;
    cout<<"4. Display all the jewellery items for which return is allowed ."<<endl;
    cout<<"5. Display all the jewellery items that are provided by 'S & S' manufacturers ."<<endl;
    cout<<"6. Display all the jewellery items whose count is less than 10 available currently with us ."<<endl;
    cout<<"7. Display all the jewellery items whose company is either 'DDmas' or 'Aura' ."<<endl;
    cout<<"8. Display all the jewellery items whose price is between 5000 to 15000 ."<<endl;
    cout<<"9. Display all the jewellery items which are necklace and price is less than 10000 ."<<endl;
    cout<<"10. Display all the jewellery items whose price is more than 20000 and are diamonds ."<<endl<<endl;
	cout<<"Enter your choice : ";
	cin>>choice;
	cout<<endl<<endl;
	switch(choice)
	{
		case 1 :
			first();
			break;
			
		case 2 :
		    second();
			break;
			
		case 3 :
		    third();
			break;
			
		case 4 :
		    fourth();
			break;
			
		case 5 :
		    fifth();
			break;
			
		case 6 :
		    sixth();
			break;
		
		case 7 :
		    seventh();
			break;
			
		case 8 :
		    eighth();
			break;
			
		case 9 :
		    ninth();
			break;
			
		case 10 :
		    tenth();
			break;
							
		default:
		    cout<<"invalid input";						
	}
}
return 0;
}
