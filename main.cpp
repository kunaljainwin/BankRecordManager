
#include<iostream>
#include<vector>
#include<map>
#include<regex>
#include<fstream>
#include<limits>
#include<sstream>
#include<string>
#include<cstring>
// local header files

#include "header.h"

using namespace std;
 

class CMain{
    
    public:
    long m_snNextAccountNum=0;
    vector<tagRecord*> vecRecord;
    map<long long,tagRecord *>mapRecord;

    void menu(){
        cout << "\n***************************************" << endl;
        cout << "       WELCOME TO STAR BANK      \n";
        cout << "***************************************" << endl;
        cout << "Please choose an option to proceed" << endl;

        cout << "\n1. OPEN NEW RECORD";
        cout << "\n2. MODIFY A RECORD";
        cout << "\n3. DELETE A RECORD";
        cout << "\n4. DISPLAY A RECORD";
        cout << "\n5. DISPLAY ALL RECORDS";
        cout << "\n6. IMPORT RECORDS FROM FILE";
        cout << "\n7. EXPORT RECORDS TO FILE";
        cout << "\n19. EXIT";
        // END
        cout << "\nYour Choice: ";
    }
    void AddRecord(){
        
       tagRecord *ptrtagRecord=new tagRecord;
        ptrtagRecord->CreateRecord();
        ptrtagRecord->SetAccountNo(vecRecord.size()+1);
            cout << "\nYour Account No. is: " <<ptrtagRecord->GetAccountNumber();
    cout << "\nKeep this for future reference.";
        vecRecord.push_back(ptrtagRecord);
        mapRecord[atoll(ptrtagRecord->GetMobile().c_str())]=ptrtagRecord;
        // write to file
        //no

        // completed
    }
    void ModifyARecord(){
        puts("Choose from the option below");
        puts("Modify using Account Number (1)");
        puts("Modify using Mobile Number (2)");
        string strChoice;
        cin>>strChoice;
        cin.clear();
        if(strChoice=="1"){
            string strAccountNo;
            cout<<"Enter Account Number: ";
            cin>>strAccountNo;
        if(stoi(strAccountNo)>vecRecord.size()||stoi(strAccountNo)<0){
            cout<<"Invalid Account Number";
            return;
        }
           vecRecord[stoi(strAccountNo)-1]->ModifyRecord();
        }
        else if(strChoice=="2"){
           string strMobileNo;
         do{
            cout<<"Enter Mobile Number: ";
            cin>>strMobileNo;
         }
         while(!IsValidMobileNumber(strMobileNo));

            mapRecord[atoll(strMobileNo.c_str())]->ModifyRecord();
        }
        else{
            puts("Invalid Choice");
            return ;
        }
        
        WriteRecordsToBinary();

        // give option to modify any field
       
        // modify record from vector
        // modify record from file

        // completed

    }
    void DeleteARecord(){
        long nAccountNo;
        cout << "Enter Account Number to delete: ";
        cin >> nAccountNo;
        // delete record from vector
        vecRecord[nAccountNo]->CloseRecord();
        puts("Record Deleted");
        // delete record from file
        // completed
    }
    
 void DisplayARecord(){
    // search by account number
    // display all details
    // completed
    long nAccountNo;
    cout << "Enter Account Number to display: ";
    cin >> nAccountNo;
    if(nAccountNo>vecRecord.size()||nAccountNo<=0){
        cout<<"Invalid Account Number";
        return;
    }
  vecRecord[nAccountNo-1]->DisplayRecord();
  

 }
 void DisplayAllRecords(){
     for(auto it=vecRecord.begin();it!=vecRecord.end();it++){
        if(((*it)->nServiceFlag&DELETED)==DELETED)
            continue;
         (*it)->DisplayRecord();
     }
 }

// File Handling
void ReadRecordsFromBinary(){
    // read from file
    
    fstream inFile;
   
    inFile.open("bank.bin",ios::binary| ios::in);
    if(!inFile){
        cout<<"File not found";
        return;
    }
    else{
    // Create a record
    // push data to vector
    // push data to map
    // completed
    puts("File found");
     tagRecord *ptrtagRecord=new tagRecord;
    while(inFile.read(reinterpret_cast<char *>(ptrtagRecord), sizeof(tagRecord)-48)){
       
        ptrtagRecord->ReadServiceData(inFile);
        vecRecord.push_back(ptrtagRecord);
        mapRecord[atoll(ptrtagRecord->GetMobile().c_str())]=ptrtagRecord;
        ptrtagRecord=new tagRecord;
        


    }
    
    }


    
}
void WriteRecordsToBinary(){
    // memory free karna mat bhulna
    // delete file
    // write to file
    remove("bank.bin");
    fstream outFile;
    outFile.open("bank.bin", ios::out | ios::binary | ios::app);
    long SIZE=vecRecord.size();
    for(int lnCounter=0;lnCounter<SIZE;lnCounter++){
        // outFile.write(reinterpret_cast<char *>(*it), sizeof(tagRecord));
outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]), sizeof(tagRecord)-48);
 if((vecRecord[lnCounter]->nServiceFlag&SAVINGS_ACCOUNT)==SAVINGS_ACCOUNT){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[SAVINGS_ACCOUNT]), sizeof(tagSavingAccount));
 }
 if((vecRecord[lnCounter]->nServiceFlag&CURRENT_ACCOUNT)==CURRENT_ACCOUNT){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[CURRENT_ACCOUNT]), sizeof(tagCurrentAccount));
 }
 if((vecRecord[lnCounter]->nServiceFlag&FIXED_DEPOSIT)==FIXED_DEPOSIT){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[FIXED_DEPOSIT]), sizeof(tagFixedDeposit));
 }
 if((vecRecord[lnCounter]->nServiceFlag&MEDICAL_INSURANCE)==MEDICAL_INSURANCE){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[MEDICAL_INSURANCE]), sizeof(tagMedicalInsurance));
 }
 if((vecRecord[lnCounter]->nServiceFlag&MUTUAL_FUND)==MUTUAL_FUND){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[MUTUAL_FUND]), sizeof(tagMutualFund));
 }if((vecRecord[lnCounter]->nServiceFlag&DEMAT)==DEMAT){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[DEMAT]), sizeof(tagDemat));
 }if((vecRecord[lnCounter]->nServiceFlag&ESTATEMENT)==ESTATEMENT){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[ESTATEMENT]), sizeof(tagEStatement));
 }if((vecRecord[lnCounter]->nServiceFlag&PASSBOOK)==PASSBOOK){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[PASSBOOK]), sizeof(tagPassbook));
 }if((vecRecord[lnCounter]->nServiceFlag&LOCKER)==LOCKER){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[LOCKER]), sizeof(tagLocker));
 }if((vecRecord[lnCounter]->nServiceFlag&NOMINATION)==NOMINATION){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[NOMINATION]), sizeof(tagNomination));
 }if((vecRecord[lnCounter]->nServiceFlag&LIFE_INSURANCE)==LIFE_INSURANCE){
    outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[LIFE_INSURANCE]), sizeof(tagLifeInsurance));
 }
// FRee memory used by services
    for(auto &it:vecRecord[lnCounter]->mapService){
        free(it.second);
    }

free(vecRecord[lnCounter]);
    }

    outFile.close();

    // completed
}
// Import and Export
void ImportRecords(){
// todo



}
void ExportRecords(){
 // Read all binary
    fstream lFStarBank;
    lFStarBank.open("bank.bin", ios::in | ios::binary);
    fstream lExportFile;
    // create csv file
    remove("export.csv");
    lExportFile.open("export.csv", ios::out | ios::trunc);
    // loop through all records
    lExportFile << "Account Number,First Name,Last Name,City,Mobile,Email,Saving Account Balance,Current Account Balance,Fixed Deposit count,Fixed Deposit Amount,Mutual Fund Amount,Demat,Nomination count,n1,n2,n3,Life Insurance count,Insurance policy coverage" << endl;
    lExportFile << endl;
    for(int lnCounter=0;lnCounter<vecRecord.size();lnCounter++){
        // read record
        // write to csv
      vecRecord [lnCounter]->ExportRecord(lExportFile);
      lExportFile<<endl;

    }
    // save csv
    lFStarBank.close();
    lExportFile.close();
}

 };


void ReleaseMode(){

CMain app;
app.ReadRecordsFromBinary();
    try
    {
        // Block of code to try
        // AutoIncrement();
    }
    catch (exception &e)
    {
        // Error handling
        cout << "Error occured";
    }

    int lcChoice; // updated by kunal to int for more options in menu
   
    do
    {

       app.menu();

        cin >> lcChoice;

        switch (lcChoice)
        {
        case 1:
            app.AddRecord();
            break;
        case 2:
            app.ModifyARecord();
            break;
        case 3:
            app.DeleteARecord();
            break;
        case 4:
            app.DisplayARecord();
            break;
        case 5:
            app.DisplayAllRecords();
            break;
        case 6:
            app.ImportRecords();
            break;
        case 7:
            app.ExportRecords();
            break;
        
        case 19:
            app.WriteRecordsToBinary();
            cout << "\n\nThanks for using our Services.\nHave a nice day!";
            break;
        
        default:
            cout << "Invalid Option";
            break;
        }
      
    } while (lcChoice !=19);
   

}
void TestMode(){
   

}
// Driver program
int main()
 {
//     isValidAmount("1000");
    ReleaseMode();
    // cout<<sizeof(tagRecord)<<endl;
    // TestMode();
     return 0;

}

// void WriteRecordToFile()
// {

//     CAccount ac;
//     fstream outFile;

//     outFile.open("bank.bin", ios::out | ios::binary | ios::app);
//     // cout<<"size of object"<<sizeof(ac)<<endl;
//     // cout<<"size of class"<<sizeof(CAccount)<<endl;

//     // cout <<"\nBefore CreateAccount():"<< ac.GetAccountNumber() << endl;

//     ac.CreateAccount();
//     cout << "\nNext account number will be:" << ac.GetAccountNumber()+1<< endl;
//     outFile.write(reinterpret_cast<char *>(&ac), sizeof(CAccount));
//     outFile.close();
// }

// void DisplayAccount()
// {
//     CAccount lCAccount;
//     bool lbFlag = false;
//     int lnNumber;
//     do
//     {
//         cout << "1 . Search with account number" << endl;
//         cout << "2 . Search with account holder name" << endl;
//         cout << "3 . Search with account holder mobile number" << endl;
//         cout << "4 . Search with account holder email id" << endl;
//         cin >> lnNumber;
//     } while (lnNumber > 4 || lnNumber < 1);

//     if (lnNumber == 1)
//     {

//         cout << "\n\n\tEnter The account No. : ";
//         int lnAccountNumber;
//         cin >> lnAccountNumber;

//         fstream inFile;
//         inFile.open("bank.bin", ios::in | ios::binary);

//         if (!inFile)
//         {
//             cout << "File could not be open !! Press any Key...";
//             return;
//         }
//         cout << "\nBALANCE DETAILS\n";
//         while (inFile.read(reinterpret_cast<char *>(&lCAccount), sizeof(CAccount)))
//         {
//             if (lCAccount.GetAccountNumber() == lnAccountNumber)
//             {
//                 lCAccount.Report();
//                 lCAccount.GetAccountType() == 'S' ? cout << "Your Saving Account balance is RS " << lCAccount.GetAccountBalance()
//                                                   : cout << "Your Current Account balance is RS " << lCAccount.GetAccountBalance();

//                 lbFlag = true;
//             }
//         }
//         inFile.close();
//         if (lbFlag == false)
//             cout << "\n\n\t\t\tAccount number does not exist";
//     }
//     else
//     {
//         cout << "\n\n\tEnter The account holder name or mobile number or email: ";
//         char lnAccountDetail[20];
//         scanf_s("%s", lnAccountDetail);

//         fstream inFile;
//         inFile.open("bank.bin", ios::in | ios::binary);
//         if (!inFile)
//         {
//             cout << "File could not be open !! Press any Key...";
//             return;
//         }
//         cout << "\nBALANCE DETAILS\n";
//         while (inFile.read(reinterpret_cast<char *>(&lCAccount), sizeof(CAccount)))
//         {
//             // optimize this code
//             if (strcmp(lCAccount.m_strFirstName, lnAccountDetail) == 0 || strcmp(lCAccount.m_strLastName, lnAccountDetail) == 0 || strcmp(lCAccount.m_strEmail, lnAccountDetail) == 0)
//             {
//                 lCAccount.Report();
//                 lCAccount.GetAccountType() == 'S' ? cout << "Your Saving Account balance is RS " << lCAccount.GetAccountBalance()
//                                                   : cout << "Your Current Account balance is RS " << lCAccount.GetAccountBalance();

//                 lbFlag = true;
//             }
//         }
//         inFile.close();
//         if (lbFlag == false)
//             cout << "\n\n\t\t\tAccount number does not exist";
//     }
// }

// void ModifyRecord(int nNumber)
// {
//     bool lfFound = false;
//     CAccount ac;
//     fstream File;
//     File.open("bank.bin", ios::binary | ios::in | ios::out);
//     if (!File)
//     {
//         cout << "File could not be opened !! Press any Key...";
//         return;
//     }
//     while (!File.eof() && lfFound == false)
//     {
//         File.read(reinterpret_cast<char *>(&ac), sizeof(CAccount));
//         if (ac.GetAccountNumber() == nNumber)
//         {
//             ac.ShowAccount();
//             cout << "\nEnter The New Details of account" << endl;
//             ac.Modify();
//             int lnPos = (-1) * static_cast<int>(sizeof(CAccount));
//             File.seekp(lnPos, ios::cur);
//             File.write(reinterpret_cast<char *>(&ac), sizeof(CAccount));
//             cout << "\nRecord Updated";
//             lfFound = true;
//         }
//     }
//     File.close();
//     if (lfFound == false)
//         cout << "\n\nRecord Not Found ";
// }

// void DeleteRecord(int nNumber)
// {

//     bool lfFound = false;
//     CAccount ac;
//     fstream File;
//     File.open("bank.bin", ios::binary | ios::in | ios::out);
//     if (!File)
//     {
//         cout << "File could not be open !! Press any Key...";
//         return;
//     }
//     while (!File.eof() && lfFound == false)
//     {
//         File.read(reinterpret_cast<char *>(&ac), sizeof(CAccount));
//         if (ac.GetAccountNumber() == nNumber)
//         {
//             ac.ShowAccount();

//             ac.CloseAccount();
//             int lnPos = (-1) * static_cast<int>(sizeof(CAccount));
//             File.seekp(lnPos, ios::cur);
//             File.write(reinterpret_cast<char *>(&ac), sizeof(CAccount));
//             cout << "\nWe regret you do not like our services....\n";
//             cout << "\nAs per your request your account is closed.\nPlase Collect your account balance from the cashier.\n";
//             lfFound = true;
//         }
//     }
//     File.close();
//     if (lfFound == false)
//         cout << "\nRecord Not Found ";
// }

// void DisplayAllRecords()
// {
//     CAccount ac;
//     fstream inFile;
//     inFile.open("bank.bin", ios::in | ios::binary);
//     if (!inFile)
//     {
//         cout << "File could not be open !! Press any Key...";
//         return;
//     }
//     cout << "\n\n**************** All Accounts Record *********************\n\n";

//     while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(CAccount)))
//     {
//         ac.Report();
//     }
//     cout << "\nPress enter to return to main menu.";
//     inFile.close();
// }

// void WithdrawBalance(int nNumber, int nOption)
// {
//     int lnAmount;
//     bool lfFound = false;
//     CAccount ac;
//     fstream File;
//     File.open("bank.bin", ios::binary | ios::in | ios::out);
//     if (!File)
//     {
//         cout << "File could not be opened !! Press any Key...";
//         return;
//     }
//     while (!File.eof() && lfFound == false)
//     {
//         File.read(reinterpret_cast<char *>(&ac), sizeof(CAccount));
//         if (ac.GetAccountNumber() == nNumber)
//         {
//             ac.ShowAccount();
//             if (nOption == 1)
//             {

//                 cout << "\n\nEnter the amount to be deposited: ";
//                 cin >> lnAmount;
//                 ac.Deposit(lnAmount);
//                 cout << "\nRs" << lnAmount << " has been deposited in your account.";
//             }
//             if (nOption == 2)
//             {

//                 cout << "\n\nEnter The amount to withdraw: ";
//                 cin >> lnAmount;
//                 int lnBal = ac.GetAccountBalance() - lnAmount;
//                 if (lnBal < 0)
//                     cout << "Error....Insufficient Balance.";
//                 else
//                 {
//                     ac.Withdraw(lnAmount);
//                     cout << "\nRs" << lnAmount << " has been withdrawn from your account.";
//                 }
//             }
//             int lnPos = (-1) * static_cast<int>(sizeof(ac));
//             File.seekp(lnPos, ios::cur);
//             File.write(reinterpret_cast<char *>(&ac), sizeof(CAccount));
//             cout << "\n\nRecord Updated";
//             lfFound = true;
//         }
//     }
//     File.close();
//     if (lfFound == false)
//         cout << "\n\nRecord Not Found ";
// }

// // Added by Kunal
// // requirements
// // 1. Import records from csv, xlsx, txt
// // 2. Export records to csv, xlsx, txt, pdf
// // 3. Search records
// // 4. Add color to the console output
// // Usage:
// // SetColor(10); => green text line
// // SetColor(7); => white text line

// void ImportRecords()
// {
//     // csv
//     // xlsx
//     // txt
//     puts("Keep file in same directory as the executable file");
//     string lstrTemp = "";
//     cout << "Enter CSV file full name to import: ";
//     cin >> lstrTemp;
//     cin.clear();
//     //    cin.ignore(numeric_limits<streamsize>::max(), '\n');

//     fstream lImportCSVFile(lstrTemp, ios::in);
//     if (!lImportCSVFile)
//     {
//         cout << "CSV File could not be opened !! Press any Key...";
//         return;
//     }
//     else
//     {
//         string s;

//         getline(lImportCSVFile, s, '\n'); // remove header row

//         while (getline(lImportCSVFile, s, '\n'))
//         {
//             CAccount lCAccount;
//             stringstream lSS(s);

//             string lTemp;
//             getline(lSS, lTemp, ',');
//             lCAccount.m_nAccountNumber = lCAccount.m_snNextAccountNum++;
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strFirstName, lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strLastName, lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             lCAccount.m_fSavingAccBalance = stof(lTemp);
//             getline(lSS, lTemp, ',');
//             lCAccount.m_fCurrentAccBalance = stof(lTemp);
//             getline(lSS, lTemp, ',');
//             lCAccount.m_cAccountType = lTemp[0];
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strMobileNumber, lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strCityName, lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strEmail, lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strDematAccNumber, lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             lCAccount.m_fFixedDepositAmt = stof(lTemp);
//             getline(lSS, lTemp, ',');
//             lCAccount.m_fMedicalInsCover = stof(lTemp);
//             getline(lSS, lTemp, ',');
//             lCAccount.m_fMutualFundInvAmt = stof(lTemp);
//             getline(lSS, lTemp, ',');
//             lCAccount.m_fLifeInsPolicyCover[0] = stof(lTemp);
//             getline(lSS, lTemp, ',');
//             lCAccount.m_fLifeInsPolicyCover[1] = stof(lTemp);
//             getline(lSS, lTemp, ',');
//             lCAccount.m_fLifeInsPolicyCover[2] = stof(lTemp);
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strNominee[0], lTemp.c_str());

//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strNominee[1], lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strNominee[2], lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strNominee[3], lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strNominee[4], lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             strcpy(lCAccount.m_strNominee[5], lTemp.c_str());
//             getline(lSS, lTemp, ',');
//             lCAccount.m_strAccountStatus = lTemp[0]; // char
//             getline(lSS, lTemp, ',');
//             lCAccount.m_cLocker = lTemp[0];
//             getline(lSS, lTemp, ',');
//             lCAccount.m_cPassbook = lTemp[0];
//             getline(lSS, lTemp, ',');
//             lCAccount.m_cEStatement = lTemp[0];
//             fstream outFile;

//             outFile.open("bank.bin", ios::out | ios::binary | ios::app);
//             outFile.write(reinterpret_cast<char *>(&lCAccount), sizeof(CAccount));
//             outFile.close();
//         }
//         // // Read from csv
//         // // Create and fill object
//         // // Fill object
//         // // Write to binary

//         lImportCSVFile.close();
//         puts("Records imported successfully");
//     }
// }
// void ExportRecords()
// {
    
//     // Read all binary
//     fstream lFStarBank;
//     lFStarBank.open("bank.bin", ios::in | ios::binary);
//     fstream lExportFile;
//     // create csv file
//     remove("export.csv");
//     lExportFile.open("export.csv", ios::out | ios::trunc);

//     // loop through all records
//     CAccount lCAccount;
//     lExportFile << "Account Number,First Name,Last Name,Saving Account Balance,Current Account Balance,Account Type,Mobile Number,City Name,Email Address,Demat Account Number,Fixed Deposit,Medical Insurance Cover,Mutual Fund Investment Amount,Cover0,Cover1,Cover2,Nominee0,Nominee1,Nominee2,Nominee3,Nominee4,Nominee5,Account Status,Locker,Passbook,E Statement";
//     lExportFile << endl;
//     while (lFStarBank.read(reinterpret_cast<char *>(&lCAccount), sizeof(CAccount)))
//     {
//         // Write to csv
//         lExportFile << lCAccount.m_nAccountNumber;
//         lExportFile << ',';
        
//         lExportFile << lCAccount.m_strFirstName;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strLastName;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_fSavingAccBalance;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_fCurrentAccBalance;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_cAccountType;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strMobileNumber;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strCityName;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strEmail;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strDematAccNumber;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_fFixedDepositAmt;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_fMedicalInsCover;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_fMutualFundInvAmt;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_fLifeInsPolicyCover[0];
//         lExportFile << ',';
//         lExportFile << lCAccount.m_fLifeInsPolicyCover[1];
//         lExportFile << ',';
//         lExportFile << lCAccount.m_fLifeInsPolicyCover[2];
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strNominee[0];

//         lExportFile << ',';

//         lExportFile << lCAccount.m_strNominee[1];
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strNominee[2];
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strNominee[3];
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strNominee[4];
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strNominee[5];
//         lExportFile << ',';
//         lExportFile << lCAccount.m_strAccountStatus;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_cLocker;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_cPassbook;
//         lExportFile << ',';
//         lExportFile << lCAccount.m_cEStatement;
//         lExportFile << '\n';
//     }
//     // save csv
//     lFStarBank.close();
//     lExportFile.close();
// }


