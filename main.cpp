
#include <iostream>
#include <vector>
#include <map>
#include <regex>
#include <fstream>
#include <limits>
#include <sstream>
#include <string>
#include <cstring>
// local header files
#include "header.h"

using namespace std;

class CMain
{

public:
    long m_snNextAccountNum = 0;
    vector<tagRecord *> vecRecord;
    map<long long, tagRecord *> mapRecord;

    void menu()
    {
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
    void AddRecord()
    {

        tagRecord *ptrtagRecord = new tagRecord;
        ptrtagRecord->CreateRecord();
        ptrtagRecord->SetAccountNo(vecRecord.size() + 1);
        cout << "\nYour Account No. is: " << ptrtagRecord->GetAccountNumber();
        cout << "\nKeep this for future reference.";
        vecRecord.push_back(ptrtagRecord);
        mapRecord[atoll(ptrtagRecord->GetMobile().c_str())] = ptrtagRecord;
        // write to file
        // no

        // completed
    }
    void ModifyARecord()
    {
        puts("Choose from the option below");
        puts("Modify using Account Number (1)");
        puts("Modify using Mobile Number (2)");
        string strChoice;
        cin >> strChoice;
        cin.clear();
        if (strChoice == "1")
        {
            string strAccountNo;
            cout << "Enter Account Number: ";
            cin >> strAccountNo;
            if (stoi(strAccountNo) > vecRecord.size() || stoi(strAccountNo) < 0)
            {
                cout << "Invalid Account Number";
                return;
            }
            vecRecord[stoi(strAccountNo) - 1]->ModifyRecord();
        }
        else if (strChoice == "2")
        {
            string strMobileNo;
            do
            {
                cout << "Enter Mobile Number: ";
                cin >> strMobileNo;
            } while (!IsValidMobileNumber(strMobileNo));

            mapRecord[atoll(strMobileNo.c_str())]->ModifyRecord();
        }
        else
        {
            puts("Invalid Choice");
            return;
        }

        WriteRecordsToBinary();

        // give option to modify any field

        // modify record from vector
        // modify record from file

        // completed
    }
    void DeleteARecord()
    {
        long nAccountNo;
        cout << "Enter Account Number to delete: ";
        cin >> nAccountNo;
        // delete record from vector
        vecRecord[nAccountNo]->CloseRecord();
        puts("Record Deleted");
        // delete record from file
        // completed
    }

    void DisplayARecord()
    {
        // search by account number
        // display all details
        // completed
        long nAccountNo;
        cout << "Enter Account Number to display: ";
        cin >> nAccountNo;
        if (nAccountNo > vecRecord.size() || nAccountNo <= 0)
        {
            cout << "Invalid Account Number";
            return;
        }
        vecRecord[nAccountNo - 1]->DisplayRecord();
    }
    void DisplayAllRecords()
    {
        for (auto it = vecRecord.begin(); it != vecRecord.end(); it++)
        {
            if (((*it)->nServiceFlag & DELETED) == DELETED)
                continue;
            (*it)->DisplayRecord();
        }
    }

    // File Handling
    void ReadRecordsFromBinary()
    {
        // read from file

        fstream inFile;
        string strFileName;
        do{
            puts("Enter valid file name:");
            cin>>strFileName;
        }
        while(!IsValidName(strFileName));
        
        try{
            strFileName+=".bin";
            inFile.open(strFileName, ios::binary | ios::in);
        }
        catch(exception e){
            puts("File not found");
            puts("Importing default bank.bin file");
             inFile.open("bank.bin", ios::binary | ios::in);
        }
        
        if (!inFile)
        {
            cout << "bank.bin File not found";
            return;
        }
        else
        {
            // Create a record
            // push data to vector
            // push data to map
            // completed
            puts("File found");
            tagRecord *ptrtagRecord = new tagRecord;
            while (inFile.read(reinterpret_cast<char *>(ptrtagRecord), sizeof(tagRecord) -sizeof(ptrtagRecord->mapService)))
            {
                ptrtagRecord->SetAccountNo(vecRecord.size() + 1) ; 
                ptrtagRecord->ReadServiceData(inFile);
                vecRecord.push_back(ptrtagRecord);
                mapRecord[atoll(ptrtagRecord->GetMobile().c_str())] = ptrtagRecord;
                ptrtagRecord = new tagRecord;
            }

             delete( ptrtagRecord); 
        }
    }
    void WriteRecordsToBinary()
    {
        // memory delete karna mat bhulna
        // delete file
        // write to file
        remove("bank.bin");
        fstream outFile;
        outFile.open("bank.bin", ios::out | ios::binary);
        long SIZE = vecRecord.size();
        for (int lnCounter = 0; lnCounter < SIZE; lnCounter++)
        {
            // outFile.write(reinterpret_cast<char *>(*it), sizeof(tagRecord));
            outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]), sizeof(tagRecord) - 48);
            for(auto it:vecRecord[lnCounter]->mapService){
                  if (vecRecord[lnCounter]->nServiceFlag & it.first)
            {
                outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[it.first]), mapServiceSize[it.first]);
            }
            }
            // if ((vecRecord[lnCounter]->nServiceFlag & SAVINGS_ACCOUNT) == SAVINGS_ACCOUNT)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[SAVINGS_ACCOUNT]), sizeof(tagSavingAccount));
            // }
            // if ((vecRecord[lnCounter]->nServiceFlag & CURRENT_ACCOUNT) == CURRENT_ACCOUNT)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[CURRENT_ACCOUNT]), sizeof(tagCurrentAccount));
            // }
            // if ((vecRecord[lnCounter]->nServiceFlag & FIXED_DEPOSIT) == FIXED_DEPOSIT)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[FIXED_DEPOSIT]), sizeof(tagFixedDeposit));
            // }
            // if ((vecRecord[lnCounter]->nServiceFlag & MEDICAL_INSURANCE) == MEDICAL_INSURANCE)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[MEDICAL_INSURANCE]), sizeof(tagMedicalInsurance));
            // }
            // if ((vecRecord[lnCounter]->nServiceFlag & MUTUAL_FUND) == MUTUAL_FUND)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[MUTUAL_FUND]), sizeof(tagMutualFund));
            // }
            // if ((vecRecord[lnCounter]->nServiceFlag & DEMAT) == DEMAT)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[DEMAT]), sizeof(tagDemat));
            // }
            // if ((vecRecord[lnCounter]->nServiceFlag & ESTATEMENT) == ESTATEMENT)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[ESTATEMENT]), sizeof(tagEStatement));
            // }
            // if ((vecRecord[lnCounter]->nServiceFlag & PASSBOOK) == PASSBOOK)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[PASSBOOK]), sizeof(tagPassbook));
            // }
            // if ((vecRecord[lnCounter]->nServiceFlag & LOCKER) == LOCKER)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[LOCKER]), sizeof(tagLocker));
            // }
            // if ((vecRecord[lnCounter]->nServiceFlag & NOMINATION) == NOMINATION)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[NOMINATION]), sizeof(tagNomination));
            // }
            // if ((vecRecord[lnCounter]->nServiceFlag & LIFE_INSURANCE) == LIFE_INSURANCE)
            // {
            //     outFile.write(reinterpret_cast<char *>(vecRecord[lnCounter]->mapService[LIFE_INSURANCE]), sizeof(tagLifeInsurance));
            // }
            // Free memory used by services
            for (auto &it : vecRecord[lnCounter]->mapService)
            {
                free(it.second);
            }
            // delete is faster than free , when datatype of pointer is known use delete
           delete(vecRecord[lnCounter]);


        }

        outFile.close();

        // completed
    }
    
    // Import and Export
    void ImportRecords()
    {
        // todo
    }
    void ExportRecords()
    {
        // Read all binary
        fstream lFStarBank;
        lFStarBank.open("bank.bin", ios::in | ios::binary);
        fstream lExportFile;
        // create csv file
        remove("export.csv");
        lExportFile.open("export.csv", ios::out | ios::trunc);
        \
        // loop through all records
        lExportFile << "Account Number,First Name,Last Name,City,Mobile,Email,Saving Account Balance,Current Account Balance,Fixed Deposit count,Fixed Deposit Amount,Mutual Fund Amount,Demat,Nomination count,n1,n2,n3,Life Insurance count,Insurance policy coverage" << endl;
        lExportFile << endl;
        for (int lnCounter = 0; lnCounter < vecRecord.size(); lnCounter++)
        {
            // read record
            // write to csv
            vecRecord[lnCounter]->ExportRecord(lExportFile);
            lExportFile << endl;
        }
        // save csv
        lFStarBank.close();
        lExportFile.close();
    }
};

void ReleaseMode()
{
    
    puts("Enter no. of accounts to be reserved");
    int lnNoOfAccounts;
    cin >> lnNoOfAccounts;

    CMain app;
    // Reserve memory for records
    app.vecRecord.reserve(lnNoOfAccounts);
    app.ReadRecordsFromBinary();

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

    } while (lcChoice != 19);
}
void TestMode()
{
}


// Driver program
int main()
{
mapServiceSize[SAVINGS_ACCOUNT]=sizeof(tagSavingAccount);
mapServiceSize [CURRENT_ACCOUNT]=sizeof(tagCurrentAccount);
mapServiceSize [LOCKER]=sizeof(tagLocker);
mapServiceSize [PASSBOOK]=sizeof(tagPassbook);
mapServiceSize [MEDICAL_INSURANCE]=sizeof(tagMedicalInsurance);
mapServiceSize [LIFE_INSURANCE]=sizeof(tagLifeInsurance);
mapServiceSize [MUTUAL_FUND]=sizeof(tagMutualFund);
mapServiceSize [FIXED_DEPOSIT]=sizeof(tagFixedDeposit);
mapServiceSize [DEMAT]=sizeof(tagDemat);
mapServiceSize [NOMINATION]=sizeof(tagNomination);
mapServiceSize [ESTATEMENT]=sizeof(tagEStatement);
   ReleaseMode();

    // cout<<sizeof(tagRecord)<<endl;// 184
    return 0;
}

