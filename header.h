

namespace std{
    enum ServiceType{
    SAVINGS_ACCOUNT=1,
    CURRENT_ACCOUNT=2,
    LOCKER=4,
    PASSBOOK=8,
    MEDICAL_INSURANCE=16,
    LIFE_INSURANCE=32,
    MUTUAL_FUND=64,
    FIXED_DEPOSIT=128,
    DEMAT=256,
    NOMINATION=512,
    ESTATEMENT=64,
    ACTIVE=2048,
    DELETED=4096
};
static bool isValidAmount(string strAmount){
// regex for any number

        const regex pattern("[0-9][0-9]*+[.|'']?[0-9]*");
        if(regex_match(strAmount,pattern)){
            return true;
        }
        else{
            return false;
        }
    
    

    }
   static bool IsValidMobileNumber(string strMobileNumber){
        const regex pattern("(0|91)?[6-9][0-9]{9}");

    if (regex_match(strMobileNumber, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
    }
    static bool IsValidName(string strName){
        const regex pattern("[a-zA-Z]{2,20}");

    if (regex_match(strName, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
    }
    static bool IsValidEmail(string strEmail){
        const regex pattern("[a-zA-Z0-9]+[.|'']?[a-zA-Z0-9]+@[a-zA-Z]+.com");

    if (regex_match(strEmail, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
    }
     static bool IsValidDematAccNumber(string strDematAccNumber)
{

    const regex pattern("(IN|[0-9]{2})[0-9]{14}");

    if (regex_match(strDematAccNumber, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
    }
struct tagCurrentAccount {
   float lfBalance;


   tagCurrentAccount(){
         lfBalance=0;
   }
    void Create(){
        string strAmount;
        do{
             cout << "\nPlease Enter the Amount : ";
         cin >> strAmount;
        }
        while(!isValidAmount(strAmount));
        lfBalance=stof(strAmount);
    }
    void Display(){
         cout << "\nCurrent Account Balance: " << lfBalance;
    }
    void Modify(){
            string strAmount;
            cout << "\nPlease Enter the Amount to be Deposited: ";
            cin >> strAmount;
            lfBalance+=stof(strAmount);
    }
};
struct tagSavingAccount {
   float lfBalance;
    tagSavingAccount(){
            lfBalance=0;
    }

    void Create(){
        string strAmount;
        
cout << "\nPlease Enter Initial Account Balance\nMin Balance for Saving Account: Rs 1000.";
    cout << "\nMin Balance for Current Account: Rs 5000.";
        do{
             cout << "\nPlease Enter the Amount : ";
         cin >> strAmount;
        }
        while(!isValidAmount(strAmount));
        lfBalance=stof(strAmount);
    }
   void Display(){
       cout << "\nSaving Account Balance: " << lfBalance;
   }    
   void Modify(){
         string strAmount;
         cout << "\nPlease Enter the Amount to be Deposited: ";
         cin >> strAmount;
         lfBalance+=stof(strAmount);
   }
};
struct tagEStatement {
    void Create(){
                
                }
           
                void Display(){
                    cout << "\nEStatement: ";
                }
                void Modify(){
                    cout << "\nEStatement: ";
                }
        };
        struct tagPassbook {
    void Create(){
                
                }
           
                void Display(){
                    cout << "\nPassbook: ";
                }
        };
struct tagDemat
{
    char lcNumber[17];
    tagDemat(){
        strcpy(lcNumber,"xxxxxxxxxxxxxxxx");
    }
    void Create(){
        string lstrTemp;
        do{
            cout << "\nPlease Enter the Demat Account Number: ";
        cin >> lstrTemp;
        }
        while (IsValidDematAccNumber(lstrTemp)==false);
        strcpy(lcNumber,lstrTemp.c_str());
        
    }
    void Display(){
        cout << "\nDemat Account Number: " << lcNumber;
   }
   void Modify(){
         string lstrTemp;
          do{
                cout << "\nPlease Enter the Demat Account Number: ";
          cin >> lstrTemp;
          }
          while (IsValidDematAccNumber(lstrTemp)==false);
          strcpy(lcNumber,lstrTemp.c_str());
   }    
};
struct tagFixedDeposit
{
    unsigned short int lnCount;
    float lfDepositAmount;
    tagFixedDeposit(){
        lnCount=0;
        lfDepositAmount=0;
    }
    void Create(){
        // not takign count input
        string strAmount;
        do{
             cout << "\nPlease Enter the Deposit Amount: ";
         cin >> strAmount;
        }
        while(isValidAmount(strAmount)==false);
        lfDepositAmount=stof(strAmount);
    }
    void Display(){
        cout << "\nFixed Deposit Amount: " << lfDepositAmount;
    }
    void Modify(){
        string strAmount;
        do{
             cout << "\nPlease Enter the Deposit Amount: ";
         cin >> strAmount;
        }
        while(isValidAmount(strAmount)==false);
        lfDepositAmount=stof(strAmount);
    }

};
struct tagLifeInsurance
{
    unsigned short int lnCount;
    float lfPolicyCoverage;
    tagLifeInsurance(){
        lnCount=0;
        lfPolicyCoverage=0;
    }
    void Create(){
        // not takign count input
        string strAmount;
        do{
             cout << "\nPlease Enter the Policy Coverage: ";
         cin >> strAmount;
        }
        while(isValidAmount(strAmount)==false);
        lfPolicyCoverage=stof(strAmount);
    }
    void Display(){
        cout << "\nLife Insurance Coverage: " << lfPolicyCoverage;
    }
    void Modify(){
        string strAmount;
        do{
        cout << "\nPlease Enter the Policy Coverage: ";
         cin >> strAmount;
        }
        while(isValidAmount(strAmount)==false);
        lfPolicyCoverage=stof(strAmount);
    }
    
};
struct tagLocker {

    void Create(){
                
                }
           
                void Display(){
                    cout << "\nLocker: ";
                }
                void Modify(){
puts("Locker Modified ");

                }
        };


struct tagMedicalInsurance
{
    float lfCoverage;
    tagMedicalInsurance(){
        lfCoverage=0;
    }
    void Create(){
        string strAmount;
        do{
             cout << "\nPlease Enter the Coverage: ";
         cin >> strAmount;
        }
        while(isValidAmount(strAmount)==false);
        lfCoverage=stof(strAmount);
    }
    void Display(){
        cout << "\nMedical Insurance Coverage: " << lfCoverage;
    }
    void Modify(){
        string strAmount;
        do{
             cout << "\nPlease Enter the Coverage: ";
         cin >> strAmount;
        }
        while(isValidAmount(strAmount)==false);
        lfCoverage=stof(strAmount);
        
    }
};
struct tagMutualFund
{
    float lfInvestmentAmount;
    tagMutualFund(){
        lfInvestmentAmount=0;
    }
    void Create(){
        string strAmount;
        do{
             cout << "\nPlease Enter the Investment Amount: ";
         cin >> strAmount;
        }
        while(isValidAmount(strAmount)==false);
        lfInvestmentAmount=stof(strAmount);
    }
    void Display(){
        cout << "\nMutual Fund Investment Amount: " << lfInvestmentAmount;
    }
    void Modify(){
        string strAmount;
        do{
             cout << "\nPlease Enter the Investment Amount: ";
         cin >> strAmount;
        }
        while(isValidAmount(strAmount)==false);
        lfInvestmentAmount=stof(strAmount);
    }
};
  struct tagNomination
{
    int lnCount;
    char lcName[3][50]={"","",""};
    tagNomination(){
        lnCount=0;
        
    }
    void Create(){
        string strName;
        cout << "\nPlease Enter the Number of Nominees: ";
       do{
         cin >> lnCount;
       }
       while(lnCount<1 || lnCount>3);
        for(int i=0;i<lnCount;i++){
            do{
                cout << "\nPlease Enter the Name of Nominee " << i+1 << ": ";
                getline(cin,strName);
                
            }
            while(IsValidName(strName)==false);
            strcpy(lcName[i],strName.c_str());
        }
    }
    void Display(){
        for(int i=0;i<lnCount;i++){
cout << "\nNominee Name: " << lcName[i];
        }
    }
    void Modify(){
        string strName;
        cout << "\nPlease Enter the Number of Nominees: ";
        cin >> lnCount;
        for(int i=0;i<lnCount;i++){
            do{
                cout << "\nPlease Enter the Name of Nominee " << i+1 << ": ";
                getline(cin,strName);
            }
            while(IsValidName(strName)==false);
            strcpy(lcName[i],strName.c_str());
        }
    }
};

struct tagRecord{
    tagRecord(){
        nAccountNo=0;
        sFirstName[0]='\0';
        sLastName[0]='\0';
        sCity[0]='\0';
        sMobile[0]='\0';
        sEmailId[0]='\0';
        nServiceFlag=0;

    }

    private:
    long nAccountNo=0;
    char sFirstName[24+1]="";
    char sLastName[24+1]="";
    char sCity[24+1]="";
    char sMobile[10+1]="";// or  long long nMobile;
    char sEmailId[40+1]="";
    
    // bool bService[11];// 11 bytes=> 88 bits
    // instead use single short int (0000 0000 0000 0000) 
    // STORE BIT WISE // 16 bits
    // 1st bit for 1st service
    // 2nd bit for 2nd service....
    
    public:
    short int nServiceFlag=0;
    map<short int ,void *>mapService;
    void CreateRecord(){
    string lstrTemp;
    nServiceFlag+=ACTIVE;
    cout << "\n\nEnter the First Name of the Account holder : ";
    cin >> lstrTemp;
    while (!IsValidName(lstrTemp))
    {
        cout << "Name should have alphabets only and length in range 2-20.";
        cout << "\nFirst Name: ";
        cin >> lstrTemp;

    }
   strcpy(sFirstName,lstrTemp.c_str());


    cout << "\nEnter the Last Name of the Account holder : ";
    cin >> lstrTemp;
    while (!IsValidName(lstrTemp))
    {
        cout << "Name should have alphabets only and length in range 2-20.";
        cout << "\nLast Name: ";
        cin >> lstrTemp;
    }
    strcpy(sLastName,lstrTemp.c_str());
    


    
    cout << "\nEnter Your City Name: ";
    cin >>lstrTemp;
     cin.clear();
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    while (!IsValidName(lstrTemp))
    {
        cout << "Plase enter a valid City Name: ";
        cin >> lstrTemp;
         cin.clear();
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    strcpy(sCity,lstrTemp.c_str());
   

    cout << "\nEnter Your Mobile Number : ";
    cin >> lstrTemp;
    cin.clear();
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (!IsValidMobileNumber(lstrTemp))
    {
        cout << "Please enter a valid mobile number: ";
        cin >> lstrTemp;
         cin.clear();
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }
    strcpy(sMobile,lstrTemp.c_str());

    cout << "\nEnter Your Email: ";
    cin >>lstrTemp;
 cin.clear();
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (!IsValidEmail(lstrTemp))
    {
        cout << "Enter a valid email: ";

        cin >> lstrTemp;
    }
    strcpy(sEmailId,lstrTemp.c_str());
    cout << "\n\nCongratulations! Your Account is Successfully Created!!";



    do
    {
        cout << "\n\nPlease choose suitable option for addtional services.";
cout<<"\n1.Saving Account";
cout<<"\n2.Current Account";

        cout << "\n3.Locker Facility";
        cout << "\n4.Passbook";
        cout << "\n5.eStatement";
        cout << "\n6.Fixed Deposit";
        cout << "\n7.Medical Insurance";
        cout << "\n8.Life Insurance";
        cout << "\n9.Nomination";
        cout << "\n10.Mutual Fund";
        cout << "\n11.Add Demat Account";
        cout << "\n19.EXIT";
        cout << "\nYour Choice: ";
        cin >> lstrTemp;
        cin.clear();
      if(lstrTemp=="1"){
           cout << "\nDo you want to avail Saving Account? (Y/N): ";
            while (true)
            {
             
                cin >>lstrTemp;
                if (lstrTemp[0] == 'Y' || lstrTemp[0]== 'y' )
                {
                    
                    tagSavingAccount*ptr=new tagSavingAccount;
                    ptr->Create();
                    ptr->Display();
                   
                    mapService[SAVINGS_ACCOUNT]=ptr;
                     nServiceFlag+=SAVINGS_ACCOUNT;
                    cout << "\nYour request for saving account has been approved.";
                    break;
                }
                 if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
                {
                    break;
                }
                cout << "\nPlease enter Y/N only";
            }
      }
      else if(lstrTemp=="2"){
                        cout << "\nDo you want to avail Current Account? (Y/N): ";
            while (true)
            {

                cin >>lstrTemp;
                if (lstrTemp[0] == 'Y' || lstrTemp[0] == 'y' )
                {
                    tagCurrentAccount*ptr=new tagCurrentAccount;
                    ptr->Create();
                    ptr->Display();
                    mapService[CURRENT_ACCOUNT]=ptr;
nServiceFlag+=CURRENT_ACCOUNT;
                    cout << "\nYour request for current account has been approved.";
                    break;
                }
                 if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
                {
                    break;
                }
                cout << "\nPlease enter Y/N only";
            }
      }
        else if(lstrTemp=="3"){
            cout << "\nDo you want to avail Locker facility? (Y/N): ";
            while (true)
            {
                
                cin >>lstrTemp;
               cin.clear();
    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');


                if (lstrTemp[0] == 'Y' || lstrTemp[0] == 'y' )
                {
                    tagLocker*ptr=new tagLocker;
                    ptr->Create();
                    ptr->Display();
                    mapService[LOCKER]=ptr;
                    nServiceFlag+=LOCKER;
                    cout << "\nYour request for locker facility has been approved.";
                    break;
                }
                 if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
                {
                    break;
                }
                cout << "\nPlease enter Y/N only";
            }
        }

        else if(lstrTemp=="4"){
            cout << "\nDo you want to avail Passbook facility? (Y/N): ";
            while (true)
            {
                
                cin >> lstrTemp;
                if(lstrTemp[0] == 'Y' ||lstrTemp[0] == 'y' )
                {
                    tagPassbook *ptr=new tagPassbook;

                    ptr->Create();
                    ptr->Display();
                    mapService[PASSBOOK]=ptr;
                    nServiceFlag+=PASSBOOK;
                    cout << "\nYour request for passbook facility has been approved.";
                    break;
                }
                 if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
                {
                    break;
                }
                cin.clear();
                cout<<"\nPlease enter Y/N only";

        }}
        else if(lstrTemp=="5"){
             cout << "\nDo you want to avail eStatement facility? (Y/N): ";
            while (true)
            {
               
                cin >> lstrTemp;
                if (lstrTemp[0] == 'Y' || lstrTemp[0] == 'y' )
                {
                    tagEStatement *ptr=new tagEStatement;
                    ptr->Create();
                    ptr->Display();
                    mapService[ESTATEMENT]=ptr;
                    nServiceFlag+=ESTATEMENT;
                    cout << "\nYour request for eStatement has been approved.\nYour account statement will be emailed to you soon.";
                    break;
                }
                 if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
                {
                    break;
                }
                cout << "\nPlease enter Y/N only";
            }
        }
        else if(lstrTemp=="6"){
            cout << "\nDo you want to avail Fixed Deposit facility? (Y/N): ";
             while (true)
            {
                
                cin >> lstrTemp;

                if (lstrTemp[0] == 'Y' || lstrTemp[0] == 'y' || lstrTemp[0]== 'N' || lstrTemp[0] == 'n')
                {
                    tagFixedDeposit*ptr=new tagFixedDeposit;
                    ptr->Create();
                    ptr->Display();
                    mapService[FIXED_DEPOSIT]=ptr;
                    nServiceFlag+=FIXED_DEPOSIT;
                    break;
                }
                 if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
                {
                    break;
                }
                cout << "\nPlease enter Y/N only";
            }
        }
        else if(lstrTemp=="7"){
              cout << "\nDo you want to avail Medical Insurance? (Y/N): ";
              while(true){                cin >> lstrTemp;
                if (lstrTemp[0] == 'Y' || lstrTemp[0] == 'y' )
                {
                   cout << "\nPlease Enter Medical Insurance Coverage Plan Amount";
          tagMedicalInsurance*ptr=new tagMedicalInsurance;
                    ptr->Create();
                    ptr->Display();
                    mapService[MEDICAL_INSURANCE]=ptr;
                    nServiceFlag+=MEDICAL_INSURANCE;
            cout << "\nTransaction successful. Your request is approved!";
           \
                    break;
                }
                 if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
                {
                    break;
                }
                 cout << "\nPlease enter Y/N only";
              }
            
        }

        else if(lstrTemp=="8"){
      
              cout<<"\nDo you want to avail Life Insurance? (Y/N): ";
              while(true){
                cin >> lstrTemp;
                if (lstrTemp[0] == 'Y' || lstrTemp[0] == 'y')
                {
                   tagLifeInsurance*ptr=new tagLifeInsurance;
                    ptr->Create();
                    ptr->Display();
                    mapService[LIFE_INSURANCE]=ptr;
                    nServiceFlag+=LIFE_INSURANCE;
                    break;

          
                }
                    if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
                    {
                        break;
                    }
                    cout << "\nPlease enter Y/N only";
        }
        }
        else if(lstrTemp=="9"){
            cout<<"\nDo you want to avail Nomination? (Y/N): ";
            while(true){
                cin >> lstrTemp;
                if (lstrTemp[0] == 'Y' || lstrTemp[0] == 'y' )
                {
            tagNomination*ptr=new tagNomination;
                    ptr->Create();
                    ptr->Display();
            mapService[NOMINATION]=ptr;
            nServiceFlag+=NOMINATION;
            break;

            }
            if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
            {
                break;
            }
            cout << "\nPlease enter Y/N only";
            }
        }

        else if(lstrTemp=="10"){
           cout<<"\nDo you want to avail Mutual Fund? (Y/N): ";
           while(true)
                cin >> lstrTemp;
                if (lstrTemp[0] == 'Y' || lstrTemp[0] == 'y' )
                {
                    tagMutualFund*ptr=new tagMutualFund;
                    ptr->Create();
                    ptr->Display();
                    mapService[MUTUAL_FUND]=ptr;
                    nServiceFlag+=MUTUAL_FUND;
                    break;
                }
                if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
                {
                    break;
                }
                cout << "\nPlease enter Y/N only";
        }
            
        else if(lstrTemp=="11"){
           cout<<"\nDo you want to avail Demat Account? (Y/N): ";
              while(true){
                  cin >> lstrTemp;
                if (lstrTemp[0] == 'Y' || lstrTemp[0] == 'y' || lstrTemp[0]== 'N' || lstrTemp[0] == 'n')
                {
                    tagDemat*ptr=new tagDemat;
                    ptr->Create();
                    ptr->Display();
                    mapService[DEMAT]=ptr;
                    nServiceFlag+=DEMAT;
                    break;
                } if(lstrTemp[0] == 'N' || lstrTemp[0] == 'n')
                {
                    break;
                }
                cout << "\nPlease enter Y/N only";
              }

            }
    
    else if (lstrTemp=="19")
    {
        cout<<"\nThank You for using our services. Have a nice day!";
    break;
    }
    else{
        cout<<"\nInvalid Choice. Please try again.";
    }
    }while(lstrTemp!="19");
    
    }

    string GetMobile(){
        return sMobile;
    }
    void SetAccountNo(long n){
        this->nAccountNo=n;
    }
    void ModifyRecord(){
        string lstrTemp;
      

      while(true){
        cout << "\nPlease enter the field you want to modify: ";
        cout << "\n1. First Name";
        cout << "\n2. Last Name";
        cout << "\n3. City";
        cout << "\n4. Mobile Number";
        cout << "\n5. Email";
        cout << "\n6. Services";
        cout << "\n7. Exit";
          cin >> lstrTemp;
        if(lstrTemp=="1"){
            do{
                 cout << "\nPlease enter the new First Name: ";
                cin>>lstrTemp;

            }
            while(IsValidName(lstrTemp)==false);
           
            strcpy(sFirstName,lstrTemp.c_str());
            
        }
        else if(lstrTemp=="2"){
            do{
                cout << "\nPlease enter the new Last Name: ";
                cin>>lstrTemp;

            }
            while(IsValidName(lstrTemp)==false);
           

            strcpy(sLastName,lstrTemp.c_str());
        }
        else if(lstrTemp=="3"){
           do{
                 cout << "\nPlease enter the new City Name: ";
                cin>>lstrTemp;

            }
            while(IsValidName(lstrTemp)==false);
           
            strcpy(sCity,lstrTemp.c_str());
        }
        else if(lstrTemp=="4"){
           do{
                 cout << "\nPlease enter the new Mobile number: ";
                cin>>lstrTemp;

            }
            while(IsValidMobileNumber(lstrTemp)==false);
           
            strcpy(sMobile,lstrTemp.c_str());
        }
        else if(lstrTemp=="5"){
          do{
                 cout << "\nPlease enter the new Last Name: ";
                cin>>lstrTemp;

            }
            while(IsValidEmail(lstrTemp)==false);
           
            strcpy(sLastName,lstrTemp.c_str());
        }
        else if(lstrTemp=="6"){
            puts("\n//////////////////Modify Services//////////////////");
            cout << "\nPlease enter the service you want to modify: ";
            cout << "\n1. Savings Account";
            cout << "\n2. Current Account";
            cout << "\n3. Fixed Deposit";
            cout << "\n4. Demat";
            cout << "\n5. Mutual Fund";
            cout << "\n6. Nomination";
            cout << "\n7. Life Insurance";
            cout << "\n8. Exit";
            while(true){
                cin >> lstrTemp;
                if(lstrTemp=="1"){
                    if((nServiceFlag&SAVINGS_ACCOUNT)==SAVINGS_ACCOUNT){
                        cout << "\nSavings Account is already availed. Do you want to modify it? (Y/N): ";
                        while(true){
                            cin >> lstrTemp;
                            if(lstrTemp[0]=='Y' || lstrTemp[0]=='y'){
                                ((tagSavingAccount*)(mapService[SAVINGS_ACCOUNT]))->Modify();
                                
                                break;
                            }
                            else if(lstrTemp[0]=='N' || lstrTemp[0]=='n'){
                                break;
                            }
                            else{
                                cout << "\nPlease enter Y/N only";
                            }
                        }
                    }
                    else{
                        cout << "\nDo you want to avail Savings Account? (Y/N): ";
                        while(true){
                            cin >> lstrTemp;
                            if(lstrTemp[0]=='Y' || lstrTemp[0]=='y'){
                                ((tagCurrentAccount*)(mapService[CURRENT_ACCOUNT]))->Modify();
                                break;
                            }
                            else if(lstrTemp[0]=='N' || lstrTemp[0]=='n'){
                                break;
                            }
                            else{
                                cout << "\nPlease enter Y/N only";
                            }
                        }
                    }
                }
                else if(lstrTemp=="2"){
                    if((nServiceFlag&CURRENT_ACCOUNT)==CURRENT_ACCOUNT){
                        cout << "\nCurrent Account is already availed. Do you want to modify it? (Y/N): ";
                        while(true){
                            cin >> lstrTemp;
                            if(lstrTemp[0]=='Y' || lstrTemp[0]=='y'){
                                tagCurrentAccount*ptr=(tagCurrentAccount*)mapService[CURRENT_ACCOUNT];
                                ptr->Modify();
                                break;
                            }
                            else if(lstrTemp[0]=='N' || lstrTemp[0]=='n'){
                                break;
                            }
                            else{
                                cout << "\nPlease enter Y/N only";
                            }
                        }
                    }
        
        }
        else if(lstrTemp=="3"){

        }
        else if(lstrTemp=="4"){

        }
        else if(lstrTemp=="5"){

        }
        else if(lstrTemp=="6"){

        }
       
        else if(lstrTemp=="7"){
            return;
        }
        else{
            cout << "\nInvalid Choice. Please try again.";
        }

    }
        }
      else if(lstrTemp=="7"){
          return;
        }
        else{
            cout << "\nInvalid Choice. Please try again.";
        }
      }
    }
    // void ModifyFirstName(){
        
    // }
    // void ModifyLastName(){

    // }
    // void ModifyCity(){

    // }
    // void ModifyMobile(){

    // }
    // void ModifyEmail(){

    // }
    
    void DisplayRecord(){
        puts("\n//////////////////Account Details//////////////////");
        
        cout << "\nAccount Number: " <<nAccountNo;
        cout << "\nFirst Name: " <<sFirstName;
        cout << "\nLast Name: " <<sLastName;
        cout << "\nCity: " <<sCity; 
        cout << "\nMobile Number: " <<sMobile;
        cout << "\nEmail: " <<sEmailId;
        if((nServiceFlag&SAVINGS_ACCOUNT)==SAVINGS_ACCOUNT)
        {
            cout << "\nAccount Type: Savings Account";
           ((tagSavingAccount*)mapService[SAVINGS_ACCOUNT])->Display();
        }
         if((nServiceFlag&CURRENT_ACCOUNT)==CURRENT_ACCOUNT)
        {
              cout << "\nAccount Type: Current Account";
           ((tagSavingAccount*)mapService[CURRENT_ACCOUNT])->Display();
        }
        if((nServiceFlag&FIXED_DEPOSIT)==FIXED_DEPOSIT)
        {
            cout << "\nAccount Type: Fixed Deposit";
            ((tagFixedDeposit*)mapService[FIXED_DEPOSIT])->Display();
        }
if((nServiceFlag&MEDICAL_INSURANCE)==MEDICAL_INSURANCE)
            {
                cout << "\nAccount Type: Medical Insurance";
                ((tagMedicalInsurance*)mapService[MEDICAL_INSURANCE])->Display();
            }
if((nServiceFlag&MUTUAL_FUND)==MUTUAL_FUND)
            {
                cout << "\nAccount Type: Mutual Fund";
                ((tagMutualFund*)mapService[MUTUAL_FUND])->Display();
            }
            if((nServiceFlag&DEMAT)==DEMAT)
            {
                cout << "\nDemat Account No.: ";
                ((tagDemat*)mapService[DEMAT])->Display();

            }
            if((nServiceFlag&ESTATEMENT)==ESTATEMENT)
            {
                cout << "\nAccount Type: E-Statement";
                ((tagEStatement*)mapService[ESTATEMENT])->Display();
            }
            if((nServiceFlag&PASSBOOK)==PASSBOOK)
            {
                cout << "\nAccount Type: Passbook";
                ((tagPassbook*)mapService[PASSBOOK])->Display();
            }
            if((nServiceFlag&LOCKER)==LOCKER)
            {
                cout << "\nAccount Type: Locker";
                ((tagLocker*)mapService[LOCKER])->Display();
            }
            if((nServiceFlag&NOMINATION)==NOMINATION)
            {
                cout << "\nAccount Type: Nominee";
                ((tagNomination*)mapService[NOMINATION])->Display();
            }
            if((nServiceFlag&LIFE_INSURANCE)==LIFE_INSURANCE)
            {
                cout << "\nAccount Type: Life Insurance";
                ((tagLifeInsurance*)mapService[LIFE_INSURANCE])->Display();
            }
            
       
        
    }
    void CloseRecord()
    {
        nServiceFlag+=DELETED;

    }
    void Deposit(){

    }
    void Withdraw(){

    }
    long  GetAccountNumber(){
        return nAccountNo;
    }
    void GetAccountBalance(){
         
    }
    void GetAccountStatus(){

    }
    static void SetLastAccountNumber(long m_nAccountNumber){

    }
    // more can be added later
    // validators
    void ReadServiceData(fstream &inFile){
        int nService=nServiceFlag;
        
        if((nServiceFlag&SAVINGS_ACCOUNT)==SAVINGS_ACCOUNT)
        {
            tagSavingAccount*ptr=new tagSavingAccount;
        inFile.read((char*)ptr,sizeof(tagSavingAccount));
            mapService[SAVINGS_ACCOUNT]=ptr;
        }
        if((nServiceFlag&CURRENT_ACCOUNT)==CURRENT_ACCOUNT)
        {
            tagCurrentAccount*ptr=new tagCurrentAccount;
            inFile.read((char*)ptr,sizeof(tagCurrentAccount));
            mapService[CURRENT_ACCOUNT]=ptr;
        }
        if((nServiceFlag&FIXED_DEPOSIT)==FIXED_DEPOSIT)
        {
            tagFixedDeposit*ptr=new tagFixedDeposit;
            inFile.read((char*)ptr,sizeof(tagFixedDeposit));
            mapService[FIXED_DEPOSIT]=ptr;
        }
        if((nServiceFlag&MEDICAL_INSURANCE)==MEDICAL_INSURANCE)
        {
            tagMedicalInsurance*ptr=new tagMedicalInsurance;
            inFile.read((char*)ptr,sizeof(tagMedicalInsurance));
            mapService[MEDICAL_INSURANCE]=ptr;
        }
        if((nServiceFlag&MUTUAL_FUND)==MUTUAL_FUND)
        {
            tagMutualFund*ptr=new tagMutualFund;
            inFile.read((char*)ptr,sizeof(tagMutualFund));
            mapService[MUTUAL_FUND]=ptr;
        }

        if((nServiceFlag&DEMAT)==DEMAT)
        {
            tagDemat*ptr=new tagDemat;
            inFile.read((char*)ptr,sizeof(tagDemat));
            mapService[DEMAT]=ptr;
        }
        if((nServiceFlag&ESTATEMENT)==ESTATEMENT)
        {
            tagEStatement*ptr=new tagEStatement;
            inFile.read((char*)ptr,sizeof(tagEStatement));
            mapService[ESTATEMENT]=ptr;
        }
       if((nServiceFlag&PASSBOOK)==PASSBOOK)
        {
            tagPassbook*ptr=new tagPassbook;
            inFile.read((char*)ptr,sizeof(tagPassbook));
            mapService[PASSBOOK]=ptr;
        }
        if((nServiceFlag&LOCKER)==LOCKER)
        {
            tagLocker*ptr=new tagLocker;
            inFile.read((char*)ptr,sizeof(tagLocker));
            mapService[LOCKER]=ptr;
        }
        if((nServiceFlag&NOMINATION)==NOMINATION)
        {
            tagNomination*ptr=new tagNomination;
            inFile.read((char*)ptr,sizeof(tagNomination));
            mapService[NOMINATION]=ptr;
        }
        if((nServiceFlag&LIFE_INSURANCE)==LIFE_INSURANCE)
        {
            tagLifeInsurance*ptr=new tagLifeInsurance;
            inFile.read((char*)ptr,sizeof(tagLifeInsurance));
            mapService[LIFE_INSURANCE]=ptr;
        }
    }
    void ExportRecord(fstream &lExportFile){
        lExportFile<<nAccountNo<<",";
        lExportFile<<sFirstName<<",";
        lExportFile<<sLastName<<",";
        lExportFile<<sCity<<",";
        lExportFile<<sMobile<<",";
        lExportFile<<sEmailId<<",";
        lExportFile<<nServiceFlag<<",";
        if((nServiceFlag&SAVINGS_ACCOUNT)==SAVINGS_ACCOUNT)
        {
            tagSavingAccount*ptr=(tagSavingAccount*)mapService[SAVINGS_ACCOUNT];
            lExportFile<<ptr->lfBalance;
        }
        else{
            lExportFile<<",";
        }
        if((nServiceFlag&CURRENT_ACCOUNT)==CURRENT_ACCOUNT)
        {
            tagCurrentAccount*ptr=(tagCurrentAccount*)mapService[CURRENT_ACCOUNT];
            lExportFile<<ptr->lfBalance<<",";
        }else{
            lExportFile<<",";
        }
        if((nServiceFlag&FIXED_DEPOSIT)==FIXED_DEPOSIT)
        {
            tagFixedDeposit*ptr=(tagFixedDeposit*)mapService[FIXED_DEPOSIT];
            lExportFile<<ptr->lnCount<<",";
            lExportFile<<ptr->lfDepositAmount<<",";
        }
        else{
            lExportFile<<", ,";
        }
        if((nServiceFlag&MUTUAL_FUND)==MUTUAL_FUND)
        {
            tagMutualFund*ptr=(tagMutualFund*)mapService[MUTUAL_FUND];
            lExportFile<<ptr->lfInvestmentAmount<<",";
        }
        else{
            lExportFile<<",";
        }
        if((nServiceFlag&MEDICAL_INSURANCE)==MEDICAL_INSURANCE)
        {
            tagMedicalInsurance*ptr=(tagMedicalInsurance*)mapService[MEDICAL_INSURANCE];
            lExportFile<<ptr->lfCoverage<<",";
        }
        else{
            lExportFile<<",";
        }
        if((nServiceFlag&DEMAT)==DEMAT)
        {
            tagDemat*ptr=(tagDemat*)mapService[DEMAT];
            lExportFile<<ptr->lcNumber<<",";
        }
        else{
            lExportFile<<",";
        }
        if((nServiceFlag&ESTATEMENT)==ESTATEMENT)
        {
            tagEStatement*ptr=(tagEStatement*)mapService[ESTATEMENT];
          
        }

        if((nServiceFlag&PASSBOOK)==PASSBOOK)
        {
            tagPassbook*ptr=(tagPassbook*)mapService[PASSBOOK];
          
        }
        if((nServiceFlag&LOCKER)==LOCKER)
        {
            tagLocker*ptr=(tagLocker*)mapService[LOCKER];
            
        }
        if((nServiceFlag&NOMINATION)==NOMINATION)
        {
            tagNomination*ptr=(tagNomination*)mapService[NOMINATION];
            lExportFile<<ptr->lnCount<<",";
            for(int i=0;i<3;i++)
            {
                lExportFile<<ptr->lcName[i]<<" "<<ptr->lcName[i];
                lExportFile<<",";

            }
        }
        else{
            lExportFile<<", , , ,";
            
        }
        if((nServiceFlag&LIFE_INSURANCE)==LIFE_INSURANCE)
        {
            tagLifeInsurance*ptr=(tagLifeInsurance*)mapService[LIFE_INSURANCE];
            lExportFile<<ptr->lnCount<<",";
            lExportFile<<ptr->lfPolicyCoverage<<" ";
        }else{
            lExportFile<<",";
        }
    }
};


}