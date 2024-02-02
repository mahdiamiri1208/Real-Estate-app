#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

struct Sign_Up_information{
    char Name[20];
    char Last_name[30];
    char Postal_code[20];
    char Username[20];
    char ID[20];
    char Mobile_number[20];
    char Email[30];
    char Password[15];
    char Password1[15];
    struct Sign_Up_information *next;
};


struct Sign_In_information{
    char Username[20];
    char Password[15];
};

//اطلاعات ملک مسکونی فروشی
struct Residential_property_information_for_sale{
    char propertyID[30];
    char Municipal_area[20];//ناحیه شهرداری
    char Exact_address[300];
    char Property_Type[20];
    char Age_of_the_property[20];
    char Size_of_the_infrastructure[20];//زیر بنا
    char Floor[20];
    char Size_of_the_main_land[20];
    char number_of_the_owner[20];
    char Number_of_bedrooms[20];
    char Price[20];
    int isActive;
    struct Residential_property_information_for_sale *next;
}*start=NULL, *last=NULL;

//اطلاعات ملک اداری فروشی
struct Office_property_information_for_sale{
    char propertyID[30];
    char Municipal_area[20];
    char Exact_address[300];
    char Property_Type[20];
    char Age_of_the_property[20];
    char Size_of_the_infrastructure[20];//زیر بنا
    char Floor[20];
    char Size_of_the_main_land[20];
    char number_of_the_owner[20];
    char Number_of_office_rooms[20];
    char Price[20];
    int isActive;
    struct Office_property_information_for_sale *next;
};

//اطلاعات زمین فروشی
struct Land_sales_information{
    char propertyID[30];
    char Municipal_area[20];
    char Exact_address[300];
    char land_Type[20];
    char Size_of_the_land[20];
    char number_of_the_owner[20];
    char Price[20];
    int isActive;
    struct Land_sales_information *next;
};

//اطلاعات ملک مسکونی اجاره ای
struct Residential_property_information_for_rent{
    char propertyID[30];
    char Municipal_area[20];
    char Exact_address[300];
    char Property_Type[10];
    char Age_of_the_property[20];
    char Size_of_the_infrastructure[20];//زیر بنا
    char Floor[20];
    char Size_of_the_main_land[20];
    char number_of_the_owner[20];
    char Number_of_bedrooms[20];
    char mortgage[20];//رهن
    char Rent[20];//اجاره
    int isActive;
    struct Residential_property_information_for_rent *next;
};

//اطلاعات ملک اداری اجاره ای
struct Office_property_information_for_rent{
    char propertyID[30];
    char Municipal_area[20];
    char Exact_address[300];
    char Property_Type[20];
    char Age_of_the_property[20];
    char Size_of_the_infrastructure[20];//زیر بنا
    char Floor[20];
    char Size_of_the_main_land[20];
    char number_of_the_owner[20];
    char Number_of_office_rooms[20];
    char mortgage[20];//رهن
    char Rent[20];//اجاره
    int isActive;
    struct Office_property_information_for_rent *next;
};

//اطلاعات زمین اجاره ای
struct Land_rent_information{
    char propertyID[30];
    char Municipal_area[20];
    char Exact_address[300];
    char land_Type[20];
    char Size_of_the_land[20];
    char number_of_the_owner[20];
    char mortgage[20];//رهن
    char Rent[20];//اجاره
    int isActive;
    struct Land_rent_information *next;
};


void main()
{
    menu();
}
void menu(void)
{
    int choice_wllcome;
    printf("                                        \e[7m                                     \e[m");
    printf("                                                                                   \e[7m** Welcome to the Real Estate app! **\e[m");
    printf("                                                                                   \e[7m                                     \e[m");

    sleep(1);
    system("cls");
    printf("\e[4m1\e[m. Sign Up\n\n");
    printf("\e[4m2\e[m. Sign In\n\n");
    printf("\e[4m3\e[m. Exit\n\n");
    printf("\e[5m>>>Please Enter Your Choice: \e[m");
    scanf("%d", &choice_wllcome);
    getchar();
    system("cls");
    switch(choice_wllcome)
        {
            case 1:
                signup();
                menu();
                break;
            case 2:
                signin();
                break;
            case 3:
                printf("\e[32mThe program closed successfully!\e[m\n");
                exit(0);
                break;
            default:
                printf("\e[31mThe entered number is unavailable!\e[m\n");
                printf("Please close the app and try again!\n");
                break;
        }
}

void signup(void)
{
    struct Sign_Up_information *start = NULL;
    struct Sign_Up_information *last = NULL;
    struct Sign_Up_information *temp;
    struct Sign_Up_information *p = malloc(sizeof(struct Sign_Up_information));
    FILE *fp1;
    fp1 = fopen("Profile_user_sign_up.txt", "r");
    if(fp1 == NULL)
    {
        printf("\e[31mERROR opening Profile_user_sign_up.txt file.\e[m\n");
        exit(1);
    }

    if(p == NULL)
    {
        printf("[MEMORY ALLOCATION FAILED]\n");
        exit(0);
    }

    FILE *fp;
    fp = fopen("Profile_user_sign_up.txt", "a");
    if (fp == NULL)
    {
        printf("ERROR: File Profile_user_sign_up.txt not found!");
        exit(1);
    }

    printf("\e[32mComplete the following sections to register...\e[m\n\n");
    int a = 0;
    printf("\n");

    while (1)
    {
        int a = 0;
        printf("Enter your Name: ");
        fgets(p->Name, sizeof(p->Name), stdin);
        p->Name[strcspn(p->Name, "\n")] = '\0';  // حذف کاراکتر \n

        for (int i = 0; i < strlen(p->Name); i++)
        {
            if (isalpha(p->Name[i]) == 0 && p->Name == "_")
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter English letters\n\n");
            continue;
        }

        if (strlen(p->Name) < 3)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter minimum \e[4m3\e[m characters\n\n");
            continue;
        }

        break;
    }



    printf("\n");

    while (1)
    {
        int a = 0;
        printf("Enter your Last name: ");
        fgets(p->Last_name, sizeof(p->Last_name), stdin);
        p->Last_name[strcspn(p->Last_name, "\n")] = '\0';  // حذف کاراکتر \n

        for (int i = 0; i < strlen(p->Last_name); i++)
        {
            if (isalpha(p->Last_name[i]) == 0 && p->Last_name == "_")
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter English letters\n\n");
            continue;
        }

        if (strlen(p->Last_name) < 3)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter minimum \e[4m3\e[m characters\n\n");
            continue;
        }

        break;
    }



    printf("\n");
    while(1)
    {
        int a = 0;
        printf("Enter your Postal code: ");
        fgets(p->Postal_code, sizeof(p->Postal_code), stdin);
        p->Postal_code[strcspn(p->Postal_code, "\n")] = '\0';  // حذف کاراکتر \n
        for (int i = 0; i < strlen(p->Postal_code); i++)
        {
            if(isdigit(p->Postal_code[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }

        if(strlen(p->Postal_code) != 10)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter \e[4m10\e[m Number\n\n");
            continue;
        }

        break;
    }



    printf("\n");


    // int foundUsername = 0;
    lable:
    while (1)
    {
        int foundUsername = 0;
        int a = 0;
        printf("Enter your Username: ");
        fgets(p->Username, sizeof(p->Username), stdin);
        p->Username[strcspn(p->Username, "\n")] = '\0';  // حذف کاراکتر \n

        while (1)
        {
            temp = malloc(sizeof(struct Sign_Up_information));
            if (fscanf(fp1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", temp->Name, temp->Last_name, temp->Postal_code, temp->Username, temp->ID,
                    temp->Mobile_number, temp->Email, temp->Password1) != 8)
            {
                break;
            }
            if (start == NULL)
            {
                start = temp;
                last = start;
                last->next = NULL;
            }
            else
            {
                last->next = temp;
                last = temp;
                last->next = NULL;
            }
        }
        temp = start;

        while (temp != NULL)
        {
            if (strcmp(temp->Username, p->Username) == 0)
            {
                printf("\e[31mThe username entered in the system exists!\e[m\n");
                printf("Try a different username\n\n");
                foundUsername = 1; // تنظیم پرچم به عنوان یافته شده
                break;
            }
            temp = temp->next;
        }

        for (int i = 0; i < strlen(p->Username); i++)
        {
            if (!(isalpha(p->Username[i]) || isdigit(p->Username[i]) || p->Username[i] == '.' || p->Username[i] == '_'))
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n\n");
            printf("You are allowed to use English letters, underlined numbers or dots\n\n");
            continue;
        }
        if (strlen(p->Username) < 3)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter a minimum of \e[4m3\e[m characters\n\n");
            continue;
        }

        if (!foundUsername)
        {
            break;
        }
        else
        {
            goto lable;
            //fseek(fp1, 0, SEEK_SET);
            //foundUsername = 0;
            //start = last = temp = NULL;

        }
    }

    printf("\n");
    while(1)
    {
        int a = 0;
        printf("Enter your ID: ");
        fgets(p->ID, sizeof(p->ID), stdin);
        p->ID[strcspn(p->ID, "\n")] = '\0';  // حذف کاراکتر \n
        for (int i = 0; i < strlen(p->ID); i++)
        {
            if(isdigit(p->ID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }

        if(strlen(p->ID) != 10)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter \e[4m10\e[m Number\n\n");
            continue;
        }

        break;
    }

    printf("\n");
    while(1)
    {
        int a = 0;
        printf("Enter your Mobile number with format 09123456789: ");
        fgets(p->Mobile_number, sizeof(p->Mobile_number), stdin);
        p->Mobile_number[strcspn(p->Mobile_number, "\n")] = '\0';  // حذف کاراکتر \n
        for (int i = 0; i < strlen(p->Mobile_number); i++)
        {
            if(isdigit(p->Mobile_number[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        if (strncmp(p->Mobile_number, "09", 2) != 0)
        {
            a++;
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("The entered format is not correct\n\n");
            continue;
        }

        if(strlen(p->Mobile_number) != 11)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter \e[4m11\e[m Number\n\n");
            continue;
        }

        break;
    }


    printf("\n");
    while(1)
    {
        int a, i, number, number1, length, at_sign = 0, signdot = 0 , space = 0, atindex;
        printf("Enter your Email: ");
        fgets(p->Email, sizeof(p->Email), stdin);
        p->Email[strcspn(p->Email, "\n")] = '\0';  // حذف کاراکتر \n

        length = strlen(p->Email);
        for(i=0; i<length; i++)
        {
            a = p->Email[i];
            if(a == '@')
            {
                atindex = i;
            }
            if(atindex == 0)
            {
                at_sign = 0;
            }
            at_sign++;
            if(at_sign > 1)
            {
                at_sign = 0;
            }
            if(a == '.')
            {
                signdot++;
                number = i;
            }
            if(a == ' ')
            {
                space++;
            }
        }

        if(at_sign != 0 && signdot != 0 && (length-number) > 3 && space != 1)
        {
            break;
        }
        else
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("your email format is wrong\n\n");
            continue;
        }
    }

    printf("\n");
    while(1)
    {
        int Upper = 0;
        int Lower = 0;
        int Digit = 0;
        int Symbol = 0;
        printf("Enter your Password: ");
        fgets(p->Password, sizeof(p->Password), stdin);
        p->Password[strcspn(p->Password, "\n")] = '\0';  // حذف کاراکتر \n
        if(strlen(p->Password) < 8)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter minimum \e[4m8\e[m character\n\n");
            continue;
        }

        for(int i = 0; i < strlen(p->Password); i++)
        {
            if (isupper(p->Password[i]))
            {
                Upper++;
            }
            else if (islower(p->Password[i]))
            {
                Lower++;
            }
            else if (isdigit(p->Password[i]))
            {
                Digit++;
            }
            else if (strchr("@#$!%&", p->Password[i]) != NULL)
            {
                Symbol++;
            }
        }
            if (Upper == 0 || Lower == 0 || Digit == 0 || Symbol == 0)
            {
                printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
                printf("Password must contain \e[1m[a-z]\e[m and \e[1m[A-Z]\e[m and \e[1m[0-9]\e[m and at least one symbol \e[1m(@ # $ ! % &)\e[m\n\n");
                continue;
            }
            printf("\n");
            printf("Enter your Password again: ");
            fgets(p->Password1, sizeof(p->Password1), stdin);
            p->Password1[strcspn(p->Password1, "\n")] = '\0';  // حذف کاراکتر \n
            if(strcmp(p->Password, p->Password1) == 0)
            {
                break;
            }
            else
            {
                printf("\e[31mThe password is not the same as the previous password!\e[m\n\n");
                printf("Enter your Password again: ");
                fgets(p->Password1, sizeof(p->Password1), stdin);
                p->Password1[strcspn(p->Password1, "\n")] = '\0';  // حذف کاراکتر \n
            }
    }

    printf("\e[32mYour registration was successful...\e[m\n");
    Sleep(2000);

    fprintf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", p->Name, p->Last_name, p->Postal_code, p->Username, p->ID, p->Mobile_number, p->Email, p->Password1);
    fclose(fp);

    if (start == NULL)
    {
        start = p;
        start->next = NULL;
        last = start;
    }
    else
    {
        last->next = p;
        last = p;
        last->next = NULL;
    }
    system("cls");
}

void signin(void)
{
    struct Sign_Up_information p;
    struct Sign_In_information *q;
    q = malloc(sizeof(struct Sign_In_information));
    if(q == NULL)
    {
        printf("\e[31mThe entered number is unavailable!\e[m\n");
        exit(0);
    }

    FILE* fp;
    fp = fopen("Profile_user_sign_up.txt", "r");
    if(fp == NULL)
    {
        printf("\e[31mERROR opening Profile_user_sign_up.txt file.\e[m\n");
        exit(1);
    }

    printf("Enter your Username :");
    fgets(q->Username, sizeof(q->Username), stdin);
    q->Username[strcspn(q->Username, "\n")] = '\0';  // حذف کاراکتر \n
    printf("Enter your password :");
    char password[30], ch;
    int i=0;
    while((ch = getch()) != '\r')
    {
        // بررسی وقتی بک اسلش وارد شود
        if (ch != 8)
        {
            // نمایش ستاره به جای کاراکتر واقعی
            printf("*");
            password[i] = ch;
            i++;
        }
        else if(ch == 13)
        {
            break;
        }
        else if (i > 0)
        {
            // حذف آخرین کاراکتر و نمایش backspace
            printf("\b \b");
            i--;
        }
    }

    password[i] = '\0';

    printf("\n");
    int answer = 0;
    while(fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s", p.Name, p.Last_name, p.Postal_code, p.Username, p.ID, p.Mobile_number, p.Email, p.Password) == 8)
    {

        if(strcmp(q->Username, p.Username) == 0 && strcmp(password, p.Password) == 0)
        {
            answer++;
            printf("\e[32mLogin successfuly!\e[m\n");
            sleep(2);
            system("cls");
            fclose(fp);
            menu2();
            break;
        }
    }
    if(answer == 0)
    {
        int a;
        printf("\e[31mpassword or username was wrong\e[m\n");
        printf("1. try again for sign in\n\n");
        printf("2. exit\n\n");
        printf("\e[5m>>>Please Enter Your Choice: \e[m");
        scanf("%d", &a);
        getchar();
        system("cls");
        switch(a)
        {
            case 1:
                signin();
                break;
            case 2:
                printf("\e[32mYour checkout was successful!\e[m");
                Sleep(2000);
                system("cls");
                menu();
                break;
            default:
                printf("\e[31mThe entered number is unavailable!\e[m\n");
                Sleep(2000);
                printf("Press any key for back to the menu...");
                getch();
                system("cls");
                menu();
                break;
        }
    }

    fclose(fp);
}

void menu2(void)
{
    int choice_sign_in;
    printf("\e[4m1\e[m. Register new information\n\n");
    printf("\e[4m2\e[m. Delete existing information\n\n");
    printf("\e[4m3\e[m. reports\n\n");
    printf("\e[4m4\e[m. User account settings\n\n");
    printf("\e[4m5\e[m. Sign out of the user account(Back to the previous menu)\n\n");
    printf("\e[5m>>>Please Enter Your Choice: \e[m");
    scanf("%d", &choice_sign_in);
    getchar();
    system("cls");
    switch(choice_sign_in)
        {
            case 1:
                Register();
                break;
            case 2:
                Delete();
                break;
            case 3:
                reports();
                break;
            case 4:
                settings();
                break;
            case 5:
                printf("\e[32mYour signout was successful!\e[m");
                sleep(3);
                system("cls");
                menu();
                break;
            default:
                printf("\e[31mThe entered number is unavailable!\e[m\n");
                Sleep(2000);
                printf("Press any key to try again...");
                getch();
                system("cls");
                menu2();
                break;
        }
}
void Register(void)
{
    int choice_sales_or_rent;
    printf("\e[4m1\e[m. \e[1mSales\e[m registration\n\n");//فروش
    printf("\e[4m2\e[m. \e[1mRent\e[m registration\n\n");//احاره
    printf("\e[4m3\e[m. Back to the previous menu\n\n");
    printf("\e[5m>>>Please Enter Your Choice: \e[m");
    scanf("%d", &choice_sales_or_rent);
    getchar();
    system("cls");
    switch(choice_sales_or_rent)
        {
            case 1:
                Sales();
                break;
            case 2:
                Rent();
                break;
            case 3:
                menu2();
                break;
            default:
                printf("\e[31mThe entered number is unavailable!\e[m\n");
                Sleep(2000);
                printf("Press any key to try again...");
                getch();
                system("cls");
                Register();
                break;
        }
}
void Sales(void)
{
    //فروش
    int choice_Registration_sale;
    printf("\e[4m1\e[m. Registration for the sale of residential property\n\n");//ملک مسکونی فروشی
    printf("\e[4m2\e[m. Registration for the sale of office property\n\n");//اداری فروشی
    printf("\e[4m3\e[m. Registration for the sale of land\n\n");//زمین فروشی
    printf("\e[4m4\e[m. Back to the previous menu\n\n");
    printf("\e[5m>>>Please Enter Your Choice: \e[m");
    scanf("%d", &choice_Registration_sale);
    getchar();
    system("cls");
    switch(choice_Registration_sale)
        {
            case 1:
                Residential_Property_For_Sale();
                break;
            case 2:
                Office_property_for_sale();
                break;
            case 3:
                Land_sales();
                break;
            case 4:
                Register();
                break;
            default:
                printf("\e[31mThe entered number is unavailable!\e[m\n");
                Sleep(2000);
                printf("Press any key to try again...");
                getch();
                system("cls");
                Sales();
                break;
        }
}
void Rent(void)
{
    //اجاره
    int choice_Registration_rent;
    printf("\e[4m1\e[m. Registration for renting a residential property\n\n");//ملک مسکونی اجاره
    printf("\e[4m2\e[m. Registration for renting office property\n\n");//اداری اجاره
    printf("\e[4m3\e[m. Registration for land lease\n\n");//زمین اجاره
    printf("\e[4m4\e[m. Back to the previous menu\n\n");
    printf("\e[5m>>>Please Enter Your Choice: \e[m");
    scanf("%d", &choice_Registration_rent);
    getchar();
    system("cls");
    switch(choice_Registration_rent)
        {
            case 1:
                Residential_property_for_rent();
                break;
            case 2:
                Office_property_for_rent();
                break;
            case 3:
                Land_rent();
                break;
            case 4:
                Register();
                break;
            default:
                printf("\e[31mThe entered number is unavailable!\e[m\n");
                Sleep(2000);
                printf("Press any key to try again...");
                getch();
                system("cls");
                Rent();
                break;
        }
}
void Delete(void)
{
    int choice_delete;
    printf("\e[4m1\e[m. Delete \e[1msales\e[m information\n\n");
    printf("\e[4m2\e[m. Delete \e[1mrent\e[m information\n\n");
    printf("\e[4m3\e[m. back to the previous menu\n\n");
    printf("\e[5m>>>Please Enter Your Choice: \e[m");
    scanf("%d", &choice_delete);
    getchar();
    system("cls");
    switch(choice_delete)
        {
            case 1:
                delete_sales();
                break;
            case 2:
                delete_rent();
                break;
            case 3:
                menu2();
                break;
            default:
                printf("\e[31mThe entered number is unavailable!\e[m\n");
                Sleep(2000);
                printf("Press any key to try again...");
                getch();
                system("cls");
                Delete();
                break;
        }
}
void delete_sales(void)
{
    int choice_delete_sales;
    printf("\e[4m1\e[m. Delete \e[1mresidential\e[m property information\n\n");
    printf("\e[4m2\e[m. Delete \e[1moffice\e[m property information\n\n");
    printf("\e[4m3\e[m. Delete \e[1mland\e[m sales information\n\n");
    printf("\e[4m4\e[m. back to the previous menu\n\n");
    printf("\e[5m>>>Please Enter Your Choice: \e[m");
    scanf("%d", &choice_delete_sales);
    getchar();
    system("cls");
    switch(choice_delete_sales)
        {
            case 1:
                Delete_residential_property_information();
                break;
            case 2:
                Delete_office_property_information();
                break;
            case 3:
                Delete_land_sales_information();
                break;
            case 4:
                Delete();
                break;
            default:
                printf("\e[31mThe entered number is unavailable!\e[m\n");
                Sleep(2000);
                printf("Press any key to try again...");
                getch();
                system("cls");
                delete_sales();
                break;
        }
}
void Delete_residential_property_information(void)
{
    int number_property = 1;
    char propertyID[30];
    int found = 0;
    struct Residential_property_information_for_sale *first = NULL;
    struct Residential_property_information_for_sale *last = NULL;
    struct Residential_property_information_for_sale *temp;
    FILE *fp, *fp2;
    fp = fopen("Residential_property_information_for_sale.txt", "r+");
    if(fp == NULL)
    {
        printf("\e[31mERROR: File Residential_property_information_for_sale.txt not found!\e[m");
        exit(1);
    }
    while (1)
    {
        temp = malloc(sizeof(struct Residential_property_information_for_sale));
        if (fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",
                   temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
                   temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_bedrooms, temp->Price, &temp->isActive) != 12)
        {
            free(temp);
            break;
        }

        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(temp->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY SALE\n\n", number_property);
            printf("PopertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Address: \e[33m%s\e[m\n\n", temp->Exact_address);
            number_property++;
            break;
        }
        temp = temp->next;
    }

    while(1)
    {
        int a = 0;
        printf("Enter the property ID to delete: ");
        scanf("%s", propertyID);
        getchar();
        for(int i = 0; i < strlen(propertyID); i++)
        {
            if(isdigit(propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    temp = first;
    while (temp != NULL)
    {
        if (strcmp(temp->propertyID, propertyID) == 0)
        {
            found++;
            if(temp->isActive == 1)
            {
                temp->isActive = 0;
                printf("\e[32mProperty deactivated successfully!\e[m");
            }
            else if(temp->isActive == 0)
            {
                printf("\e[33mProperty is already deactivated!\e[m");
                Sleep(2000);
                system("cls");
                menu2();
            }
        }
        temp = temp->next;
    }
    if (found != 0)
    {
        fp2 = fopen("temp.txt", "w");
        if (fp2 == NULL)
        {
            printf("[MEMORY ALLOCATION FAILED]\n");
            exit(1);
        }
        temp = first;
        while(temp != NULL)
        {
            fprintf(fp2, "%s\n", temp->propertyID);
            fprintf(fp2, "%s\n", temp->Municipal_area);
            fprintf(fp2, "%s\n", temp->Exact_address);
            fprintf(fp2, "%s\n", temp->Property_Type);
            fprintf(fp2, "%s\n", temp->Age_of_the_property);
            fprintf(fp2, "%s\n", temp->Size_of_the_infrastructure);
            fprintf(fp2, "%s\n", temp->Floor);
            fprintf(fp2, "%s\n", temp->Size_of_the_main_land);
            fprintf(fp2, "%s\n", temp->number_of_the_owner);
            fprintf(fp2, "%s\n", temp->Number_of_bedrooms);
            fprintf(fp2, "%s\n", temp->Price);
            fprintf(fp2, "%d\n", temp->isActive);
            temp = temp->next;
        }
        Sleep(2000);
        fclose(fp2);
        fclose(fp);
        remove("Residential_property_information_for_sale.txt");
        rename("temp.txt", "Residential_property_information_for_sale.txt");
    }
    else
    {
        printf("\e[33mproperty ID not found!\e[m");
        Sleep(2000);
        system("cls");
        menu2();
    }
    temp = first;
    while (temp != NULL)
    {
        struct Residential_property_information_for_sale *next = temp->next;
        free(temp);
        temp = next;
    }
    system("cls");
    menu2();
}
void Delete_office_property_information(void)
{
    int number1_property = 1;
    char propertyID[30];
    int found = 0;
    struct Office_property_information_for_sale *first = NULL;
    struct Office_property_information_for_sale *last = NULL;
    struct Office_property_information_for_sale *temp;
    FILE *fp, *fp2;
    fp = fopen("Office_property_information_for_sale.txt", "r+");
    if(fp == NULL)
    {
        printf("\e[31mERROR: File Office_property_information_for_sale.txt not found!\e[m");
        exit(1);
    }
    while (1)
    {
        temp = malloc(sizeof(struct Office_property_information_for_sale));
        if (fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
                   temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_office_rooms, temp->Price, &temp->isActive) != 12)
        {
            free(temp);
            break;
        }

        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(temp->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY SALE\n\n", number1_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Address: \e[33m%s\e[m\n\n", temp->Exact_address);
            number1_property++;
            break;
        }
        temp = temp->next;
    }

    while(1)
    {
        int a = 0;
        printf("Enter the property ID to delete: ");
        scanf("%s", propertyID);
        getchar();
        for(int i = 0; i < strlen(propertyID); i++)
        {
            if(isdigit(propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    temp = first;
    while (temp != NULL)
    {
        if (strcmp(temp->propertyID, propertyID) == 0)
        {
            found++;
            if(temp->isActive == 1)
            {
                temp->isActive = 0;
                printf("\e[32mProperty deactivated successfully!\e[m");
            }
            else if(temp->isActive == 0)
            {
                printf("\e[33mProperty is already deactivated!\e[m");
                Sleep(2000);
                system("cls");
                menu2();
            }
        }
        temp = temp->next;
    }
    if (found != 0)
    {
        fp2 = fopen("temp.txt", "w");
        if (fp2 == NULL)
        {
            printf("[MEMORY ALLOCATION FAILED]\n");
            exit(1);
        }
        temp = first;
        while(temp != NULL)
        {
            fprintf(fp2, "%s\n", temp->propertyID);
            fprintf(fp2, "%s\n", temp->Municipal_area);
            fprintf(fp2, "%s\n", temp->Exact_address);
            fprintf(fp2, "%s\n", temp->Property_Type);
            fprintf(fp2, "%s\n", temp->Age_of_the_property);
            fprintf(fp2, "%s\n", temp->Size_of_the_infrastructure);
            fprintf(fp2, "%s\n", temp->Floor);
            fprintf(fp2, "%s\n", temp->Size_of_the_main_land);
            fprintf(fp2, "%s\n", temp->number_of_the_owner);
            fprintf(fp2, "%s\n", temp->Number_of_office_rooms);
            fprintf(fp2, "%s\n", temp->Price);
            fprintf(fp2, "%d\n", temp->isActive);
            temp = temp->next;
        }
        Sleep(2000);
        fclose(fp2);
        fclose(fp);
        remove("Office_property_information_for_sale.txt");
        rename("temp.txt", "Office_property_information_for_sale.txt");
    }
    else
    {
        printf("\e[33mproperty ID not found!\e[m");
        Sleep(2000);
        system("cls");
        menu2();
    }
    temp = first;
    while (temp != NULL)
    {
        struct Office_property_information_for_sale *next = temp->next;
        free(temp);
        temp = next;
    }
    system("cls");
    menu2();
}
void Delete_land_sales_information(void)
{
    int number1_property = 1;
    char propertyID[30];
    int found = 0;
    struct Land_sales_information *first = NULL;
    struct Land_sales_information *last = NULL;
    struct Land_sales_information *temp;
    FILE *fp, *fp2;
    fp = fopen("Land_sales_information.txt", "r+");
    if(fp == NULL)
    {
        printf("\e[31mERROR: File Land_sales_information.txt not found!\e[m");
        exit(1);
    }
    while (1)
    {
        temp = malloc(sizeof(struct Land_sales_information));
        if (fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->land_Type, temp->Size_of_the_land,
                temp->number_of_the_owner, temp->Price, &temp->isActive) != 8)
        {
            free(temp);
            break;
        }

        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(temp->isActive == 1)
        {
            printf("%d.LAND SALE\n\n", number1_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Address: \e[33m%s\e[m\n\n", temp->Exact_address);
            number1_property++;
            break;
        }
        temp = temp->next;
    }
    while(1)
    {
        int a = 0;
        printf("Enter the property ID to delete: ");
        scanf("%s", propertyID);
        getchar();
        for(int i = 0; i < strlen(propertyID); i++)
        {
            if(isdigit(propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    temp = first;
    while (temp != NULL)
    {
        if (strcmp(temp->propertyID, propertyID) == 0)
        {
            found++;
            if(temp->isActive == 1)
            {
                temp->isActive = 0;
                printf("\e[32mProperty deactivated successfully!\e[m");
            }
            else if(temp->isActive == 0)
            {
                printf("\e[33mProperty is already deactivated!\e[m");
                Sleep(2000);
                system("cls");
                menu2();
            }
        }
        temp = temp->next;
    }
    if (found != 0)
    {
        fp2 = fopen("temp.txt", "w");
        if (fp2 == NULL)
        {
            printf("[MEMORY ALLOCATION FAILED]\n");
            exit(1);
        }
        temp = first;
        while(temp != NULL)
        {
            fprintf(fp2, "%s\n", temp->propertyID);
            fprintf(fp2, "%s\n", temp->Municipal_area);
            fprintf(fp2, "%s\n", temp->Exact_address);
            fprintf(fp2, "%s\n", temp->land_Type);
            fprintf(fp2, "%s\n", temp->Size_of_the_land);
            fprintf(fp2, "%s\n", temp->number_of_the_owner);
            fprintf(fp2, "%s\n", temp->Price);
            fprintf(fp2, "%d\n", temp->isActive);
            temp = temp->next;
        }
        Sleep(2000);
        fclose(fp2);
        fclose(fp);
        remove("Land_sales_information.txt");
        rename("temp.txt", "Land_sales_information.txt");
    }
    else
    {
        printf("\e[33mproperty ID not found!\e[m");
        Sleep(2000);
        system("cls");
        menu2();
    }
    temp = first;
    while (temp != NULL)
    {
        struct Land_sales_information *next = temp->next;
        free(temp);
        temp = next;
    }
    system("cls");
    menu2();
}
void delete_rent(void)
{
    int choice_delete_rent;
    printf("\e[4m1\e[m. Delete the rental \e[1mresidential\e[m property information\n\n");
    printf("\e[4m2\e[m. Delete the rental \e[1moffice\e[m property information\n\n");
    printf("\e[4m3\e[m. Delete the rental \e[1mland\e[m sales information\n\n");
    printf("\e[4m4\e[m. back to the previous menu\n\n");
    printf("\e[5m>>>Please Enter Your Choice: \e[m");
    scanf("%d", &choice_delete_rent);
    getchar();
    system("cls");
    switch(choice_delete_rent)
        {
            case 1:
                Delete_rental_residential_property_information();
                break;
            case 2:
                Delete_rental_office_property_information();
                break;
            case 3:
                Delete_rental_land_sales_information();
                break;
            case 4:
                Delete();
                break;
            default:
                printf("\e[31mThe entered number is unavailable!\e[m\n");
                Sleep(2000);
                printf("Press any key to try again...");
                getch();
                system("cls");
                delete_rent();
                break;
        }
}
void Delete_rental_residential_property_information(void)
{
    int number1_property = 1;
    char propertyID[30];
    int found = 0;
    struct Residential_property_information_for_rent *first = NULL;
    struct Residential_property_information_for_rent *last = NULL;
    struct Residential_property_information_for_rent *temp;
    FILE *fp, *fp2;
    fp = fopen("Residential_property_information_for_rent.txt", "r+");
    if(fp == NULL)
    {
        printf("\e[31mERROR: File Residential_property_information_for_rent.txt not found!\e[m");
        exit(1);
    }
    while (1)
    {
        temp = malloc(sizeof(struct Residential_property_information_for_rent));
        if (fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
                   temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_bedrooms, temp->mortgage, temp->Rent, &temp->isActive) != 13)
        {
            free(temp);
            break;
        }

        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(temp->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY RENT\n\n", number1_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Address: \e[33m%s\e[m\n\n", temp->Exact_address);
            number1_property++;
            break;
        }
        temp = temp->next;
    }
    while(1)
    {
        int a = 0;
        printf("Enter the property ID to delete: ");
        scanf("%s", propertyID);
        getchar();
        for(int i = 0; i < strlen(propertyID); i++)
        {
            if(isdigit(propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }
    temp = first;
    while(temp != NULL)
    {
        if (strcmp(temp->propertyID, propertyID) == 0)
        {
            found++;
            if(temp->isActive == 1)
            {
                temp->isActive = 0;
                printf("\e[32mProperty deactivated successfully!\e[m");
            }
            else if(temp->isActive == 0)
            {
                printf("\e[33mProperty is already deactivated!\e[m");
                Sleep(2000);
                system("cls");
                menu2();
            }
        }
        temp = temp->next;
    }
    if(found != 0)
    {
        fp2 = fopen("temp.txt", "w");
        if (fp2 == NULL)
        {
            printf("[MEMORY ALLOCATION FAILED]\n");
            exit(1);
        }
        temp = first;
        while(temp != NULL)
        {
            fprintf(fp2, "%s\n", temp->propertyID);
            fprintf(fp2, "%s\n", temp->Municipal_area);
            fprintf(fp2, "%s\n", temp->Exact_address);
            fprintf(fp2, "%s\n", temp->Property_Type);
            fprintf(fp2, "%s\n", temp->Age_of_the_property);
            fprintf(fp2, "%s\n", temp->Size_of_the_infrastructure);
            fprintf(fp2, "%s\n", temp->Floor);
            fprintf(fp2, "%s\n", temp->Size_of_the_main_land);
            fprintf(fp2, "%s\n", temp->number_of_the_owner);
            fprintf(fp2, "%s\n", temp->Number_of_bedrooms);
            fprintf(fp2, "%s\n", temp->mortgage);
            fprintf(fp2, "%s\n", temp->Rent);
            fprintf(fp2, "%d\n", temp->isActive);
            temp = temp->next;
        }
        Sleep(2000);
        fclose(fp2);
        fclose(fp);
        remove("Residential_property_information_for_rent.txt");
        rename("temp.txt", "Residential_property_information_for_rent.txt");
    }
    else
    {
        printf("\e[33mproperty ID not found!\e[m");
        Sleep(2000);
        system("cls");
        menu2();
    }
    temp = first;
    while (temp != NULL)
    {
        struct Residential_property_information_for_rent *next = temp->next;
        free(temp);
        temp = next;
    }
    system("cls");
    menu2();
}
void Delete_rental_office_property_information(void)
{
    int number1_property = 1;
    char propertyID[30];
    int found = 0;
    struct Office_property_information_for_rent *first = NULL;
    struct Office_property_information_for_rent *last = NULL;
    struct Office_property_information_for_rent *temp;
    FILE *fp, *fp2;
    fp = fopen("Office_property_information_for_rent.txt", "r+");
    if(fp == NULL)
    {
        printf("\e[31mERROR: File Office_property_information_for_rent.txt not found!\e[m");
        exit(1);
    }
    while (1)
    {
        temp = malloc(sizeof(struct Office_property_information_for_rent));
        if (fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
                   temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_office_rooms, temp->mortgage, temp->Rent, &temp->isActive) != 13)
        {
            free(temp);
            break;
        }

        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(temp->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY RENT\n\n", number1_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Address: \e[33m%s\e[m\n\n", temp->Exact_address);
            number1_property++;
            break;
        }
        temp = temp->next;
    }
    while(1)
    {
        int a = 0;
        printf("Enter the property ID to delete: ");
        scanf("%s", propertyID);
        getchar();
        for(int i = 0; i < strlen(propertyID); i++)
        {
            if(isdigit(propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    temp = first;
    while (temp != NULL)
    {
        if (strcmp(temp->propertyID, propertyID) == 0)
        {
            found++;
            if(temp->isActive == 1)
            {
                temp->isActive = 0;
                printf("\e[32mProperty deactivated successfully!\e[m");
            }
            else if(temp->isActive == 0)
            {
                printf("\e[33mProperty is already deactivated!\e[m");
                Sleep(2000);
                system("cls");
                menu2();
            }
        }
        temp = temp->next;
    }
    if (found != 0)
    {
        fp2 = fopen("temp.txt", "w");
        if (fp2 == NULL)
        {
            printf("[MEMORY ALLOCATION FAILED]\n");
            exit(1);
        }
        temp = first;
        while(temp != NULL)
        {
            fprintf(fp2, "%s\n", temp->propertyID);
            fprintf(fp2, "%s\n", temp->Municipal_area);
            fprintf(fp2, "%s\n", temp->Exact_address);
            fprintf(fp2, "%s\n", temp->Property_Type);
            fprintf(fp2, "%s\n", temp->Age_of_the_property);
            fprintf(fp2, "%s\n", temp->Size_of_the_infrastructure);
            fprintf(fp2, "%s\n", temp->Floor);
            fprintf(fp2, "%s\n", temp->Size_of_the_main_land);
            fprintf(fp2, "%s\n", temp->number_of_the_owner);
            fprintf(fp2, "%s\n", temp->Number_of_office_rooms);
            fprintf(fp2, "%s\n", temp->mortgage);
            fprintf(fp2, "%s\n", temp->Rent);
            fprintf(fp2, "%d\n", temp->isActive);
            temp = temp->next;
        }
        Sleep(2000);
        fclose(fp2);
        fclose(fp);
        remove("Office_property_information_for_rent.txt");
        rename("temp.txt", "Office_property_information_for_rent.txt");
    }
    else
    {
        printf("\e[33mproperty ID not found!\e[m");
        Sleep(2000);
        system("cls");
        menu2();
    }
    temp = first;
    while (temp != NULL)
    {
        struct Office_property_information_for_rent *next = temp->next;
        free(temp);
        temp = next;
    }
    system("cls");
    menu2();
}
void Delete_rental_land_sales_information(void)
{
    int number1_property = 1;
    char propertyID[30];
    int found = 0;
    struct Land_rent_information *first = NULL;
    struct Land_rent_information *last = NULL;
    struct Land_rent_information *temp;
    FILE *fp, *fp2;
    fp = fopen("Land_rent_information.txt", "r+");
    if(fp == NULL)
    {
        printf("\e[31mERROR: File Land_rent_information.txt not found!\e[m");
        exit(1);
    }
    while (1)
    {
        temp = malloc(sizeof(struct Land_rent_information));
        if (fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->land_Type, temp->Size_of_the_land,
                temp->number_of_the_owner, temp->mortgage, temp->Rent, &temp->isActive) != 9)
        {
            free(temp);
            break;
        }

        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(temp->isActive == 1)
        {
            printf("%d.LAND RENT\n\n", number1_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Address: \e[33m%s\e[m\n\n", temp->Exact_address);
            number1_property++;
            break;
        }
        temp = temp->next;
    }
    while(1)
    {
        int a = 0;
        printf("Enter the property ID to delete: ");
        scanf("%s", propertyID);
        getchar();
        for(int i = 0; i < strlen(propertyID); i++)
        {
            if(isdigit(propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    temp = first;
    while (temp != NULL)
    {
        if (strcmp(temp->propertyID, propertyID) == 0)
        {
            found++;
            if(temp->isActive == 1)
            {
                temp->isActive = 0;
                printf("\e[32mProperty deactivated successfully!\e[m");
            }
            else if(temp->isActive == 0)
            {
                printf("\e[33mProperty is already deactivated!\e[m");
                Sleep(2000);
                system("cls");
                menu2();
            }
        }
        temp = temp->next;
    }
    if (found != 0)
    {
        fp2 = fopen("temp.txt", "w");
        if (fp2 == NULL)
        {
            printf("[MEMORY ALLOCATION FAILED]\n");
            exit(1);
        }
        temp = first;
        while(temp != NULL)
        {
            fprintf(fp2, "%s\n", temp->propertyID);
            fprintf(fp2, "%s\n", temp->Municipal_area);
            fprintf(fp2, "%s\n", temp->Exact_address);
            fprintf(fp2, "%s\n", temp->land_Type);
            fprintf(fp2, "%s\n", temp->Size_of_the_land);
            fprintf(fp2, "%s\n", temp->number_of_the_owner);
            fprintf(fp2, "%s\n", temp->mortgage);
            fprintf(fp2, "%s\n", temp->Rent);
            fprintf(fp2, "%d\n", temp->isActive);
            temp = temp->next;
        }
        Sleep(2000);
        fclose(fp2);
        fclose(fp);
        remove("Land_rent_information.txt");
        rename("temp.txt", "Land_rent_information.txt");
    }
    else
    {
        printf("\e[33mproperty ID not found!\e[m");
        Sleep(2000);
        system("cls");
        menu2();
    }
    temp = first;
    while (temp != NULL)
    {
        struct Land_rent_information *next = temp->next;
        free(temp);
        temp = next;
    }
    system("cls");
    menu2();
}
void reports(void)
{
    int choice_report;
    printf("\e[4m1\e[m. The number of \e[1mproperties\e[m in the system\n\n");
    printf("\e[4m2\e[m. Properties available in a specific \e[1mmunicipal area\e[m\n\n");
    printf("\e[4m3\e[m. Properties with specific \e[1mbuilding age\e[m\n\n");
    printf("\e[4m4\e[m. Properties with specific \e[1minfrastructure\e[m\n\n");
    printf("\e[4m5\e[m. Properties with special \e[1mprice\e[m\n\n");
    printf("\e[4m6\e[m. Residential properties with specific \e[1mnumber of bedrooms\e[m\n\n");
    printf("\e[4m7\e[m. Office properties with specific \e[1mnumber of rooms\e[m\n\n");
    printf("\e[4m8\e[m. Rental properties with specific limits for \e[1mmortgage\e[m and \e[1mrent\e[m\n\n");
    printf("\e[4m9\e[m. All Residential apartments available in a particular \e[1mfloor\e[m\n\n");
    printf("\e[4m10\e[m. All Office apartments available in a particular \e[1mfloor\e[m\n\n");
    printf("\e[4m11\e[m. Back to the previous menu\n\n");
    printf("\e[5m>>>Please Enter Your Choice: \e[m");
    scanf("%d", &choice_report);
    getchar();
    system("cls");
    switch(choice_report)
        {
            case 1:
                number_of_properties_in_system();
                break;
            case 2:
                properties_in_specific_municipal_area();
                break;
            case 3:
                properties_specific_building_age();
                break;
            case 4:
                properties_specific_infrastructure();
                break;
            case 5:
                properties_special_price();
                break;
            case 6:
                residential_properties_specific_number_of_bedrooms();
                break;
            case 7:
                office_properties_specific_number_of_rooms();
                break;
            case 8:
                rental_properties_specific_limits_for_mortgage_and_rent();
                break;
            case 9:
                Residential_apartments_in_particular_floor();
                break;
            case 10:
                office_apartments_in_particular_floor();
                break;
            case 11:
                menu2();
                break;
            default:
                printf("\e[31mThe entered number is unavailable!\e[m\n");
                printf("Press any key to try again...");
                getch();
                system("cls");
                reports();
                break;
        }
}
void number_of_properties_in_system(void)
{
    int number_of_properties = 0;
    int number_property = 1;
    FILE* file;
    file = fopen("Residential_property_information_for_sale.txt", "r+");
    struct Residential_property_information_for_sale *first = NULL;
    struct Residential_property_information_for_sale *last = NULL;
    struct Residential_property_information_for_sale* temp;

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    printf("All properties of the system are as follows:");
    printf("\n");
    printf("\e[36m******************************************************\e[m\n\n");
    while(1)
    {
       struct Residential_property_information_for_sale* temp = malloc(sizeof(struct Residential_property_information_for_sale));
        if(fscanf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
            temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_bedrooms, temp->Price, &temp->isActive) != 12)
        {
            free(temp);
            break;
        }
        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(temp->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY SALE\n\n", number_property);
            printf("PopertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp->Number_of_bedrooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp->Price);
            number_property++;
            number_of_properties++;
            break;
        }
        temp = temp->next;
    }

    fclose(file);

    temp = first;
    while(temp != NULL)
    {
        struct Residential_property_information_for_sale *next = temp->next;
        free(temp);
        temp = next;
    }

    if (number_property == 1)
    {
        printf("\e[31mThere is no property in residential sale\e[m\n\n");
    }


    //officeeeeeeeeeeeee

    printf("\e[36m******************************************************\e[m\n\n");
    int number1_property = 1;
    FILE* file1;
    file1 = fopen("Office_property_information_for_sale.txt", "r+");
    struct Office_property_information_for_sale *first1 = NULL;
    struct Office_property_information_for_sale *last1 = NULL;
    struct Office_property_information_for_sale *temp1;

    if (file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
       struct Office_property_information_for_sale* temp1 = malloc(sizeof(struct Office_property_information_for_sale));
        if(fscanf(file1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp1->propertyID, temp1->Municipal_area, temp1->Exact_address, temp1->Property_Type, temp1->Age_of_the_property,
            temp1->Size_of_the_infrastructure, temp1->Floor, temp1->Size_of_the_main_land, temp1->number_of_the_owner, temp1->Number_of_office_rooms, temp1->Price, &temp1->isActive) != 12)
        {
            free(temp1);
            break;
        }
        if(first1 == NULL)
        {
            first1 = temp1;
            last1 = first1;
            last1->next = NULL;
        }
        else
        {
            last1->next = temp1;
            last1 = temp1;
            last1->next = NULL;
        }
    }

    temp1 = first1;
    while(temp1 != NULL)
    {
        while(temp1->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY SALE\n\n", number1_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp1->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp1->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp1->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp1->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp1->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp1->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp1->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp1->Number_of_office_rooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp1->Price);
            number1_property++;
            number_of_properties++;
            break;
        }
        temp1 = temp1->next;
    }

    fclose(file1);

    temp1 = first1;
    while(temp1 != NULL)
    {
        struct Office_property_information_for_sale *next = temp1->next;
        free(temp1);
        temp1 = next;
    }

    if (number1_property == 1)
    {
        printf("\e[31mThere is no property in office sale\e[m\n\n");
    }


    //land_saleeeeeeeeeee


    printf("\e[36m******************************************************\e[m\n\n");
    int number2_property = 1;
    FILE* file2;
    file2 = fopen("Land_sales_information.txt", "r+");
    struct Land_sales_information *first2 = NULL;
    struct Land_sales_information *last2 = NULL;
    struct Land_sales_information* temp2;

    if(file2 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
    struct Land_sales_information* temp2 = malloc(sizeof(struct Land_sales_information));
        if(fscanf(file2, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp2->propertyID, temp2->Municipal_area, temp2->Exact_address, temp2->land_Type, temp2->Size_of_the_land,
                temp2->number_of_the_owner, temp2->Price, &temp2->isActive) != 8)
        {
            free(temp2);
            break;
        }
        if(first2 == NULL)
        {
            first2 = temp2;
            last2 = first2;
            last2->next = NULL;
        }
        else
        {
            last2->next = temp2;
            last2 = temp2;
            last2->next = NULL;
        }
    }

    temp2 = first2;
    while(temp2 != NULL)
    {
        while(temp2->isActive == 1)
        {
                printf("%d.LAND SALE\n\n", number2_property);
                printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp2->propertyID);
                printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp2->Municipal_area);
                printf("Address: \e[33m%s\e[m\n", temp2->Exact_address);
                printf("Type of land: \e[4m\e[33m%s\e[m\e[m\n", temp2->land_Type);
                printf("Size of the land: \e[4m\e[33m%s\e[m\e[m\n", temp2->Size_of_the_land);
                printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp2->number_of_the_owner);
                printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp2->Price);
                number2_property++;
                number_of_properties++;
                break;
        }
        temp2 = temp2->next;
    }

    fclose(file2);

    temp2 = first2;
    while(temp2 != NULL)
    {
        struct Land_sales_information *next = temp2->next;
        free(temp2);
        temp2 = next;
    }

    if (number2_property == 1)
    {
        printf("\e[31mThere is no property in land sale\e[m\n\n");
    }


    //residental_renttttttttttt


    printf("\e[36m******************************************************\e[m\n\n");
    int number3_property = 1;
    FILE* file3;
    file3 = fopen("Residential_property_information_for_rent.txt", "r+");
    struct Residential_property_information_for_rent *first3 = NULL;
    struct Residential_property_information_for_rent *last3 = NULL;
    struct Residential_property_information_for_rent* temp3;

    if (file3 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
    struct Residential_property_information_for_rent* temp3 = malloc(sizeof(struct Residential_property_information_for_rent));
        if(fscanf(file3, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp3->propertyID, temp3->Municipal_area, temp3->Exact_address, temp3->Property_Type, temp3->Age_of_the_property,
            temp3->Size_of_the_infrastructure, temp3->Floor, temp3->Size_of_the_main_land, temp3->number_of_the_owner, temp3->Number_of_bedrooms, temp3->mortgage, temp3->Rent, &temp3->isActive) != 13)
        {
            free(temp3);
            break;
        }
        if (first3 == NULL)
        {
            first3 = temp3;
            last3 = first3;
            last3->next = NULL;
        }
        else
        {
            last3->next = temp3;
            last3 = temp3;
            last3->next = NULL;
        }
    }
    temp3 = first3;
    while(temp3 != NULL)
    {
        while(temp3->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY RENT\n\n", number3_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp3->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp3->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp3->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp3->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp3->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp3->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp3->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp3->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp3->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp3->Number_of_bedrooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp3->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp3->Rent);
            number3_property++;
            number_of_properties++;
            break;
        }
        temp3 = temp3->next;
    }

    fclose(file3);

    temp3 = first3;
    while(temp3 != NULL)
    {
        struct Residential_property_information_for_rent *next = temp3->next;
        free(temp3);
        temp3 = next;
    }

    if(number3_property == 1)
    {
        printf("\e[31mThere is no property in residential rent\e[m\n\n");
    }


    //OFFICE_RENTTTTTTTT

    printf("\e[36m******************************************************\e[m\n\n");
    int number4_property = 1;
    FILE* file4;
    file4 = fopen("Office_property_information_for_rent.txt", "r+");
    struct Office_property_information_for_rent *first4 = NULL;
    struct Office_property_information_for_rent *last4 = NULL;
    struct Office_property_information_for_rent* temp4;

    if (file4 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        struct Office_property_information_for_rent* temp4 = malloc(sizeof(struct Office_property_information_for_rent));
        if(fscanf(file4, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp4->propertyID, temp4->Municipal_area, temp4->Exact_address, temp4->Property_Type, temp4->Age_of_the_property,
            temp4->Size_of_the_infrastructure, temp4->Floor, temp4->Size_of_the_main_land, temp4->number_of_the_owner, temp4->Number_of_office_rooms, temp4->mortgage, temp4->Rent, &temp4->isActive) != 13)
        {
            free(temp4);
            break;
        }
        if (first4 == NULL)
        {
            first4 = temp4;
            last4 = first4;
            last4->next = NULL;
        }
        else
        {
            last4->next = temp4;
            last4 = temp4;
            last4->next = NULL;
        }
    }
    temp4 = first4;
    while(temp4 != NULL)
    {
        while(temp4->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY RENT\n\n", number4_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp4->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp4->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp4->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp4->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp4->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp4->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp4->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp4->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp4->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp4->Number_of_office_rooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp4->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp4->Rent);
            number4_property++;
            number_of_properties++;
            break;
        }
        temp4 = temp4->next;
    }

    fclose(file4);

    temp4 = first4;
    while(temp4 != NULL)
    {
        struct Office_property_information_for_rent *next = temp4->next;
        free(temp4);
        temp4 = next;
    }

    if(number4_property == 1)
    {
        printf("\e[31mThere is no property in office rent\e[m\n\n");
    }


    //land_renttttttttttttttt


    printf("\e[36m******************************************************\e[m\n\n");
    int number5_property = 1;
    FILE* file5;
    file5 = fopen("Land_rent_information.txt", "r+");
    struct Land_rent_information *first5 = NULL;
    struct Land_rent_information *last5 = NULL;
    struct Land_rent_information* temp5;

    if (file5 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        struct Land_rent_information* temp5 = malloc(sizeof(struct Land_rent_information));
        if(fscanf(file5, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp5->propertyID, temp5->Municipal_area, temp5->Exact_address, temp5->land_Type, temp5->Size_of_the_land,
                temp5->number_of_the_owner, temp5->mortgage, temp5->Rent, &temp5->isActive) != 9)
        {
            free(temp5);
            break;
        }
        if(first5 == NULL)
        {
            first5 = temp5;
            last5 = first5;
            last5->next = NULL;
        }
        else
        {
            last5->next = temp5;
            last5 = temp5;
            last5->next = NULL;
        }
    }

    temp5 = first5;
    while(temp5 != NULL)
    {
        while(temp5->isActive == 1)
        {
            printf("%d.LAND RENT\n\n", number5_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp5->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp5->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp5->Exact_address);
            printf("Type of land: \e[4m\e[33m%s\e[m\e[m\n", temp5->land_Type);
            printf("Size of the land: \e[4m\e[33m%s\e[m\e[m\n", temp5->Size_of_the_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp5->number_of_the_owner);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp5->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp5->Rent);
            number5_property++;
            number_of_properties++;
            break;
        }
        temp5 = temp5->next;
    }

    fclose(file5);

    temp5 = first5;
    while(temp5 != NULL)
    {
        struct Land_rent_information *next = temp5->next;
        free(temp5);
        temp5 = next;
    }
    if(number5_property == 1)
    {
        printf("\e[31mThere is no property in land rent\e[m\n\n");
    }



    printf("\e[36m******************************************************\e[m\n\n");
    printf("The number of all properties in the system is \e[33m%d\e[m\n\n", number_of_properties);
    printf("Press any key for back to the previous menu...");
    getch();
    system("cls");
    reports();

}
void properties_in_specific_municipal_area(void)
{
    char municipal[30];
    int number_property = 1;
    FILE* file;
    file = fopen("Residential_property_information_for_sale.txt", "r+");
    struct Residential_property_information_for_sale *first = NULL;
    struct Residential_property_information_for_sale *last = NULL;
    struct Residential_property_information_for_sale* temp;

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }


    while(1)
    {
        int a = 0;
        printf("Enter the municipal area what you want: ");
        fgets(municipal, sizeof(municipal), stdin);
        municipal[strcspn(municipal, "\n")] = '\0';  // حذف کاراکتر \n

        for(int i = 0; i < strlen(municipal); i++)
        {
            if(!isdigit(municipal[i]))
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter a Number\n\n");
            continue;
        }
        break;
    }

    printf("\n");
    printf("\e[36m******************************************************\e[m\n\n");
    while(1)
    {
       struct Residential_property_information_for_sale* temp = malloc(sizeof(struct Residential_property_information_for_sale));
        if(fscanf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
            temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_bedrooms, temp->Price, &temp->isActive) != 12)
        {
            free(temp);
            break;
        }
        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(atoi(temp->Municipal_area) == atoi(municipal) && temp->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY SALE\n\n", number_property);
            printf("PopertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp->Number_of_bedrooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp->Price);
            number_property++;
            break;

        }
        temp = temp->next;
    }

    fclose(file);

    temp = first;
    while(temp != NULL)
    {
        struct Residential_property_information_for_sale *next = temp->next;
        free(temp);
        temp = next;
    }

    if (number_property == 1)
    {
        printf("\e[31mThe specified residential property sale does not exist\e[m\n\n");
    }


    //officeeeeeeeeeeeee

    printf("\e[36m******************************************************\e[m\n\n");
    int number1_property = 1;
    FILE* file1;
    file1 = fopen("Office_property_information_for_sale.txt", "r+");
    struct Office_property_information_for_sale *first1 = NULL;
    struct Office_property_information_for_sale *last1 = NULL;
    struct Office_property_information_for_sale *temp1;

    if (file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
       struct Office_property_information_for_sale* temp1 = malloc(sizeof(struct Office_property_information_for_sale));
        if(fscanf(file1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp1->propertyID, temp1->Municipal_area, temp1->Exact_address, temp1->Property_Type, temp1->Age_of_the_property,
            temp1->Size_of_the_infrastructure, temp1->Floor, temp1->Size_of_the_main_land, temp1->number_of_the_owner, temp1->Number_of_office_rooms, temp1->Price, &temp1->isActive) != 12)
        {
            free(temp1);
            break;
        }
        if(first1 == NULL)
        {
            first1 = temp1;
            last1 = first1;
            last1->next = NULL;
        }
        else
        {
            last1->next = temp1;
            last1 = temp1;
            last1->next = NULL;
        }
    }

    temp1 = first1;
    while(temp1 != NULL)
    {
        while(atoi(temp1->Municipal_area) == atoi(municipal) && temp1->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY SALE\n\n", number1_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp1->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp1->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp1->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp1->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp1->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp1->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp1->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp1->Number_of_office_rooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp1->Price);
            number1_property++;
            break;
        }
        temp1 = temp1->next;
    }

    fclose(file1);

    temp1 = first1;
    while(temp1 != NULL)
    {
        struct Office_property_information_for_sale *next = temp1->next;
        free(temp1);
        temp1 = next;
    }

    if (number1_property == 1)
    {
        printf("\e[31mThe specified office property sale does not exist\e[m\n\n");
    }


    //land_saleeeeeeeeeee


    printf("\e[36m******************************************************\e[m\n\n");
    int number2_property = 1;
    FILE* file2;
    file2 = fopen("Land_sales_information.txt", "r+");
    struct Land_sales_information *first2 = NULL;
    struct Land_sales_information *last2 = NULL;
    struct Land_sales_information* temp2;

    if(file2 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
    struct Land_sales_information* temp2 = malloc(sizeof(struct Land_sales_information));
        if(fscanf(file2, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp2->propertyID, temp2->Municipal_area, temp2->Exact_address, temp2->land_Type, temp2->Size_of_the_land,
                temp2->number_of_the_owner, temp2->Price, &temp2->isActive) != 8)
        {
            free(temp2);
            break;
        }
        if(first2 == NULL)
        {
            first2 = temp2;
            last2 = first2;
            last2->next = NULL;
        }
        else
        {
            last2->next = temp2;
            last2 = temp2;
            last2->next = NULL;
        }
    }

    temp2 = first2;
    while(temp2 != NULL)
    {
        while(atoi(temp2->Municipal_area) == atoi(municipal) && temp2->isActive == 1)
        {
                printf("%d.LAND SALE\n\n", number2_property);
                printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp2->propertyID);
                printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp2->Municipal_area);
                printf("Address: \e[33m%s\e[m\n", temp2->Exact_address);
                printf("Type of land: \e[4m\e[33m%s\e[m\e[m\n", temp2->land_Type);
                printf("Size of the land: \e[4m\e[33m%s\e[m\e[m\n", temp2->Size_of_the_land);
                printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp2->number_of_the_owner);
                printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp2->Price);
                number2_property++;
                break;
        }
        temp2 = temp2->next;
    }

    fclose(file2);

    temp2 = first2;
    while(temp2 != NULL)
    {
        struct Land_sales_information *next = temp2->next;
        free(temp2);
        temp2 = next;
    }

    if (number2_property == 1)
    {
            printf("\e[31mThe specified land sale does not exist\e[m\n\n");
    }


    //residental_renttttttttttt


    printf("\e[36m******************************************************\e[m\n\n");
    int number3_property = 1;
    FILE* file3;
    file3 = fopen("Residential_property_information_for_rent.txt", "r+");
    struct Residential_property_information_for_rent *first3 = NULL;
    struct Residential_property_information_for_rent *last3 = NULL;
    struct Residential_property_information_for_rent* temp3;

    if (file3 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
    struct Residential_property_information_for_rent* temp3 = malloc(sizeof(struct Residential_property_information_for_rent));
        if(fscanf(file3, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp3->propertyID, temp3->Municipal_area, temp3->Exact_address, temp3->Property_Type, temp3->Age_of_the_property,
            temp3->Size_of_the_infrastructure, temp3->Floor, temp3->Size_of_the_main_land, temp3->number_of_the_owner, temp3->Number_of_bedrooms, temp3->mortgage, temp3->Rent, &temp3->isActive) != 13)
        {
            free(temp3);
            break;
        }
        if (first3 == NULL)
        {
            first3 = temp3;
            last3 = first3;
            last3->next = NULL;
        }
        else
        {
            last3->next = temp3;
            last3 = temp3;
            last3->next = NULL;
        }
    }
    temp3 = first3;
    while(temp3 != NULL)
    {
        while(atoi(temp3->Municipal_area) == atoi(municipal) && temp3->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY RENT\n\n", number3_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp3->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp3->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp3->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp3->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp3->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp3->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp3->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp3->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp3->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp3->Number_of_bedrooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp3->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp3->Rent);
            number3_property++;
            break;
        }
        temp3 = temp3->next;
    }

    fclose(file3);

    temp3 = first3;
    while(temp3 != NULL)
    {
        struct Residential_property_information_for_rent *next = temp3->next;
        free(temp3);
        temp3 = next;
    }

    if(number3_property == 1)
    {
        printf("\e[31mThe specified residential property rent does not exist\e[m\n\n");
    }


    //OFFICE_RENTTTTTTTT

    printf("\e[36m******************************************************\e[m\n\n");
    int number4_property = 1;
    FILE* file4;
    file4 = fopen("Office_property_information_for_rent.txt", "r+");
    struct Office_property_information_for_rent *first4 = NULL;
    struct Office_property_information_for_rent *last4 = NULL;
    struct Office_property_information_for_rent* temp4;

    if (file4 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        struct Office_property_information_for_rent* temp4 = malloc(sizeof(struct Office_property_information_for_rent));
        if(fscanf(file4, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp4->propertyID, temp4->Municipal_area, temp4->Exact_address, temp4->Property_Type, temp4->Age_of_the_property,
            temp4->Size_of_the_infrastructure, temp4->Floor, temp4->Size_of_the_main_land, temp4->number_of_the_owner, temp4->Number_of_office_rooms, temp4->mortgage, temp4->Rent, &temp4->isActive) != 13)
        {
            free(temp4);
            break;
        }
        if (first4 == NULL)
        {
            first4 = temp4;
            last4 = first4;
            last4->next = NULL;
        }
        else
        {
            last4->next = temp4;
            last4 = temp4;
            last4->next = NULL;
        }
    }
    temp4 = first4;
    while(temp4 != NULL)
    {
        while(atoi(temp4->Municipal_area) == atoi(municipal) && temp4->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY RENT\n\n", number4_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp4->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp4->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp4->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp4->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp4->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp4->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp4->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp4->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp4->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp4->Number_of_office_rooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp4->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp4->Rent);
            number4_property++;
            break;
        }
        temp4 = temp4->next;
    }

    fclose(file4);

    temp4 = first4;
    while(temp4 != NULL)
    {
        struct Office_property_information_for_rent *next = temp4->next;
        free(temp4);
        temp4 = next;
    }

    if(number4_property == 1)
    {
        printf("\e[31mThe specified office property rent does not exist\e[m\n\n");
    }


    //land_renttttttttttttttt


    printf("\e[36m******************************************************\e[m\n\n");
    int number5_property = 1;
    FILE* file5;
    file5 = fopen("Land_rent_information.txt", "r+");
    struct Land_rent_information *first5 = NULL;
    struct Land_rent_information *last5 = NULL;
    struct Land_rent_information* temp5;

    if (file5 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        struct Land_rent_information* temp5 = malloc(sizeof(struct Land_rent_information));
        if(fscanf(file5, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp5->propertyID, temp5->Municipal_area, temp5->Exact_address, temp5->land_Type, temp5->Size_of_the_land,
                temp5->number_of_the_owner, temp5->mortgage, temp5->Rent, &temp5->isActive) != 9)
        {
            free(temp5);
            break;
        }
        if(first5 == NULL)
        {
            first5 = temp5;
            last5 = first5;
            last5->next = NULL;
        }
        else
        {
            last5->next = temp5;
            last5 = temp5;
            last5->next = NULL;
        }
    }

    temp5 = first5;
    while(temp5 != NULL)
    {
        while(atoi(temp5->Municipal_area) == atoi(municipal) && temp5->isActive == 1)
        {
            printf("%d.LAND RENT\n\n", number5_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp5->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp5->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp5->Exact_address);
            printf("Type of land: \e[4m\e[33m%s\e[m\e[m\n", temp5->land_Type);
            printf("Size of the land: \e[4m\e[33m%s\e[m\e[m\n", temp5->Size_of_the_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp5->number_of_the_owner);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp5->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp5->Rent);
            number5_property++;
            break;
        }
        temp5 = temp5->next;
    }

    fclose(file5);

    temp5 = first5;
    while(temp5 != NULL)
    {
        struct Land_rent_information *next = temp5->next;
        free(temp5);
        temp5 = next;
    }

    if (number5_property == 1)
    {
        printf("\e[31mThe specified land rent does not exist\e[m\n\n");
    }

    printf("\e[36m******************************************************\e[m\n\n");
    printf("Press any key for back to the previous menu...");
    getch();
    system("cls");
    reports();
}
void properties_specific_building_age(void)
{
    char age1[30], age2[30];
    int number_property = 1;
    FILE* file;
    file = fopen("Residential_property_information_for_sale.txt", "r+");
    struct Residential_property_information_for_sale *first = NULL;
    struct Residential_property_information_for_sale *last = NULL;
    struct Residential_property_information_for_sale* temp;

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        int a = 0;
        printf("The lowest year considered: ");
        fgets(age1, sizeof(age1), stdin);
        age1[strcspn(age1, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(age1); i++)
        {
            if(isdigit(age1[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    while(1)
    {
        int a = 0;
        printf("The highest year considered: ");
        fgets(age2, sizeof(age2), stdin);
        age2[strcspn(age2, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(age2); i++)
        {
            if(isdigit(age2[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    printf("\n");
    printf("\e[36m******************************************************\e[m\n\n");
    while(1)
    {
       struct Residential_property_information_for_sale* temp = malloc(sizeof(struct Residential_property_information_for_sale));
        if(fscanf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
            temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_bedrooms, temp->Price, &temp->isActive) != 12)
        {
            free(temp);
            break;
        }
        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(atoi(temp->Age_of_the_property) >= atoi(age1) && atoi(temp->Age_of_the_property) <= atoi(age2) && temp->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY SALE\n\n", number_property);
            printf("PopertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp->Number_of_bedrooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp->Price);
            number_property++;
            break;

        }
        temp = temp->next;
    }

    fclose(file);

    temp = first;
    while(temp != NULL)
    {
        struct Residential_property_information_for_sale *next = temp->next;
        free(temp);
        temp = next;
    }

    if (number_property == 1)
    {
        printf("\e[31mThe specified residential property sale does not exist\e[m\n\n");
    }


    //officeeeeeeeeeeeee

    printf("\e[36m******************************************************\e[m\n\n");
    int number1_property = 1;
    FILE* file1;
    file1 = fopen("Office_property_information_for_sale.txt", "r+");
    struct Office_property_information_for_sale *first1 = NULL;
    struct Office_property_information_for_sale *last1 = NULL;
    struct Office_property_information_for_sale *temp1;

    if (file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
       struct Office_property_information_for_sale* temp1 = malloc(sizeof(struct Office_property_information_for_sale));
        if(fscanf(file1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp1->propertyID, temp1->Municipal_area, temp1->Exact_address, temp1->Property_Type, temp1->Age_of_the_property,
            temp1->Size_of_the_infrastructure, temp1->Floor, temp1->Size_of_the_main_land, temp1->number_of_the_owner, temp1->Number_of_office_rooms, temp1->Price, &temp1->isActive) != 12)
        {
            free(temp1);
            break;
        }
        if(first1 == NULL)
        {
            first1 = temp1;
            last1 = first1;
            last1->next = NULL;
        }
        else
        {
            last1->next = temp1;
            last1 = temp1;
            last1->next = NULL;
        }
    }

    temp1 = first1;
    while(temp1 != NULL)
    {
        while(atoi(temp1->Age_of_the_property) >= atoi(age1) && atoi(temp1->Age_of_the_property) <= atoi(age2) && temp1->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY SALE\n\n", number1_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp1->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp1->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp1->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp1->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp1->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp1->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp1->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp1->Number_of_office_rooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp1->Price);
            number1_property++;
            break;
        }
        temp1 = temp1->next;
    }

    fclose(file1);

    temp1 = first1;
    while(temp1 != NULL)
    {
        struct Office_property_information_for_sale *next = temp1->next;
        free(temp1);
        temp1 = next;
    }

    if (number1_property == 1)
    {
        printf("\e[31mThe specified office property sale does not exist\e[m\n\n");
    }


    //residental_renttttttttttt


    printf("\e[36m******************************************************\e[m\n\n");
    int number3_property = 1;
    FILE* file3;
    file3 = fopen("Residential_property_information_for_rent.txt", "r+");
    struct Residential_property_information_for_rent *first3 = NULL;
    struct Residential_property_information_for_rent *last3 = NULL;
    struct Residential_property_information_for_rent* temp3;

    if (file3 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
    struct Residential_property_information_for_rent* temp3 = malloc(sizeof(struct Residential_property_information_for_rent));
        if(fscanf(file3, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp3->propertyID, temp3->Municipal_area, temp3->Exact_address, temp3->Property_Type, temp3->Age_of_the_property,
            temp3->Size_of_the_infrastructure, temp3->Floor, temp3->Size_of_the_main_land, temp3->number_of_the_owner, temp3->Number_of_bedrooms, temp3->mortgage, temp3->Rent, &temp3->isActive) != 13)
        {
            free(temp3);
            break;
        }
        if (first3 == NULL)
        {
            first3 = temp3;
            last3 = first3;
            last3->next = NULL;
        }
        else
        {
            last3->next = temp3;
            last3 = temp3;
            last3->next = NULL;
        }
    }
    temp3 = first3;
    while(temp3 != NULL)
    {
        while(atoi(temp3->Age_of_the_property) >= atoi(age1) && atoi(temp3->Age_of_the_property) <= atoi(age2) && temp3->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY RENT\n\n", number3_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp3->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp3->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp3->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp3->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp3->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp3->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp3->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp3->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp3->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp3->Number_of_bedrooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp3->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp3->Rent);
            number3_property++;
            break;
        }
        temp3 = temp3->next;
    }

    fclose(file3);

    temp3 = first3;
    while(temp3 != NULL)
    {
        struct Residential_property_information_for_rent *next = temp3->next;
        free(temp3);
        temp3 = next;
    }

    if(number3_property == 1)
    {
        printf("\e[31mThe specified residential property rent does not exist\e[m\n\n");
    }


    //OFFICE_RENTTTTTTTT

    printf("\e[36m******************************************************\e[m\n\n");
    int number4_property = 1;
    FILE* file4;
    file4 = fopen("Office_property_information_for_rent.txt", "r+");
    struct Office_property_information_for_rent *first4 = NULL;
    struct Office_property_information_for_rent *last4 = NULL;
    struct Office_property_information_for_rent* temp4;

    if (file4 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        struct Office_property_information_for_rent* temp4 = malloc(sizeof(struct Office_property_information_for_rent));
        if(fscanf(file4, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp4->propertyID, temp4->Municipal_area, temp4->Exact_address, temp4->Property_Type, temp4->Age_of_the_property,
            temp4->Size_of_the_infrastructure, temp4->Floor, temp4->Size_of_the_main_land, temp4->number_of_the_owner, temp4->Number_of_office_rooms, temp4->mortgage, temp4->Rent, &temp4->isActive) != 13)
        {
            free(temp4);
            break;
        }
        if (first4 == NULL)
        {
            first4 = temp4;
            last4 = first4;
            last4->next = NULL;
        }
        else
        {
            last4->next = temp4;
            last4 = temp4;
            last4->next = NULL;
        }
    }
    temp4 = first4;
    while(temp4 != NULL)
    {
        while(atoi(temp4->Age_of_the_property) >= atoi(age1) && atoi(temp4->Age_of_the_property) <= atoi(age2) && temp4->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY RENT\n\n", number4_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp4->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp4->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp4->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp4->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp4->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp4->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp4->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp4->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp4->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp4->Number_of_office_rooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp4->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp4->Rent);
            number4_property++;
            break;
        }
        temp4 = temp4->next;
    }

    fclose(file4);

    temp4 = first4;
    while(temp4 != NULL)
    {
        struct Office_property_information_for_rent *next = temp4->next;
        free(temp4);
        temp4 = next;
    }

    if(number4_property == 1)
    {
        printf("\e[31mThe specified office property rent does not exist\e[m\n\n");
    }

    printf("\e[36m******************************************************\e[m\n\n");
    printf("Press any key for back to the previous menu...");
    getch();
    system("cls");
    reports();

}
void properties_specific_infrastructure(void)
{
    char infrastructure1[30], infrastructure2[30];
    int number_property = 1;
    FILE* file;
    file = fopen("Residential_property_information_for_sale.txt", "r+");
    struct Residential_property_information_for_sale *first = NULL;
    struct Residential_property_information_for_sale *last = NULL;
    struct Residential_property_information_for_sale* temp;

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        int a = 0;
        printf("The lowest infrastructure considered: ");
        fgets(infrastructure1, sizeof(infrastructure1), stdin);
        infrastructure1[strcspn(infrastructure1, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(infrastructure1); i++)
        {
            if(isdigit(infrastructure1[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

        while(1)
    {
        int a = 0;
        printf("The highest infrastructure considered: ");
        fgets(infrastructure2, sizeof(infrastructure2), stdin);
        infrastructure2[strcspn(infrastructure2, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(infrastructure2); i++)
        {
            if(isdigit(infrastructure2[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    printf("\n");
    printf("\e[36m******************************************************\e[m\n\n");
    while(1)
    {
       struct Residential_property_information_for_sale* temp = malloc(sizeof(struct Residential_property_information_for_sale));
        if(fscanf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
            temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_bedrooms, temp->Price, &temp->isActive) != 12)
        {
            free(temp);
            break;
        }
        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(atoi(temp->Size_of_the_infrastructure) >= atoi(infrastructure1) && atoi(temp->Size_of_the_infrastructure) <= atoi(infrastructure2) && temp->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY SALE\n\n", number_property);
            printf("PopertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp->Number_of_bedrooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp->Price);
            number_property++;
            break;

        }
        temp = temp->next;
    }

    fclose(file);

    temp = first;
    while(temp != NULL)
    {
        struct Residential_property_information_for_sale *next = temp->next;
        free(temp);
        temp = next;
    }

    if (number_property == 1)
    {
        printf("\e[31mThe specified residential property sale does not exist\e[m\n\n");
    }


    //officeeeeeeeeeeeee

    printf("\e[36m******************************************************\e[m\n\n");
    int number1_property = 1;
    FILE* file1;
    file1 = fopen("Office_property_information_for_sale.txt", "r+");
    struct Office_property_information_for_sale *first1 = NULL;
    struct Office_property_information_for_sale *last1 = NULL;
    struct Office_property_information_for_sale *temp1;

    if (file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
       struct Office_property_information_for_sale* temp1 = malloc(sizeof(struct Office_property_information_for_sale));
        if(fscanf(file1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp1->propertyID, temp1->Municipal_area, temp1->Exact_address, temp1->Property_Type, temp1->Age_of_the_property,
            temp1->Size_of_the_infrastructure, temp1->Floor, temp1->Size_of_the_main_land, temp1->number_of_the_owner, temp1->Number_of_office_rooms, temp1->Price, &temp1->isActive) != 12)
        {
            free(temp1);
            break;
        }
        if(first1 == NULL)
        {
            first1 = temp1;
            last1 = first1;
            last1->next = NULL;
        }
        else
        {
            last1->next = temp1;
            last1 = temp1;
            last1->next = NULL;
        }
    }

    temp1 = first1;
    while(temp1 != NULL)
    {
        while(atoi(temp1->Size_of_the_infrastructure) >= atoi(infrastructure1) && atoi(temp1->Size_of_the_infrastructure) <= atoi(infrastructure2) && temp1->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY SALE\n\n", number1_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp1->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp1->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp1->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp1->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp1->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp1->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp1->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp1->Number_of_office_rooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp1->Price);
            number1_property++;
            break;
        }
        temp1 = temp1->next;
    }

    fclose(file1);

    temp1 = first1;
    while(temp1 != NULL)
    {
        struct Office_property_information_for_sale *next = temp1->next;
        free(temp1);
        temp1 = next;
    }

    if (number1_property == 1)
    {
        printf("\e[31mThe specified office property sale does not exist\e[m\n\n");
    }


    //land_saleeeeeeeeeee


    printf("\e[36m******************************************************\e[m\n\n");
    int number2_property = 1;
    FILE* file2;
    file2 = fopen("Land_sales_information.txt", "r+");
    struct Land_sales_information *first2 = NULL;
    struct Land_sales_information *last2 = NULL;
    struct Land_sales_information* temp2;

    if(file2 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
    struct Land_sales_information* temp2 = malloc(sizeof(struct Land_sales_information));
        if(fscanf(file2, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp2->propertyID, temp2->Municipal_area, temp2->Exact_address, temp2->land_Type, temp2->Size_of_the_land,
                temp2->number_of_the_owner, temp2->Price, &temp2->isActive) != 8)
        {
            free(temp2);
            break;
        }
        if(first2 == NULL)
        {
            first2 = temp2;
            last2 = first2;
            last2->next = NULL;
        }
        else
        {
            last2->next = temp2;
            last2 = temp2;
            last2->next = NULL;
        }
    }

    temp2 = first2;
    while(temp2 != NULL)
    {
        while(atoi(temp2->Size_of_the_land) >= atoi(infrastructure1) && atoi(temp2->Size_of_the_land) <= atoi(infrastructure2) && temp2->isActive == 1)
        {
                printf("%d.LAND SALE\n\n", number2_property);
                printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp2->propertyID);
                printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp2->Municipal_area);
                printf("Address: \e[33m%s\e[m\n", temp2->Exact_address);
                printf("Type of land: \e[4m\e[33m%s\e[m\e[m\n", temp2->land_Type);
                printf("Size of the land: \e[4m\e[33m%s\e[m\e[m\n", temp2->Size_of_the_land);
                printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp2->number_of_the_owner);
                printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp2->Price);
                number2_property++;
                break;
        }
        temp2 = temp2->next;
    }

    fclose(file2);

    temp2 = first2;
    while(temp2 != NULL)
    {
        struct Land_sales_information *next = temp2->next;
        free(temp2);
        temp2 = next;
    }

    if (number2_property == 1)
    {
            printf("\e[31mThe specified land sale does not exist\e[m\n\n");
    }


    //residental_renttttttttttt


    printf("\e[36m******************************************************\e[m\n\n");
    int number3_property = 1;
    FILE* file3;
    file3 = fopen("Residential_property_information_for_rent.txt", "r+");
    struct Residential_property_information_for_rent *first3 = NULL;
    struct Residential_property_information_for_rent *last3 = NULL;
    struct Residential_property_information_for_rent* temp3;

    if (file3 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
    struct Residential_property_information_for_rent* temp3 = malloc(sizeof(struct Residential_property_information_for_rent));
        if(fscanf(file3, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp3->propertyID, temp3->Municipal_area, temp3->Exact_address, temp3->Property_Type, temp3->Age_of_the_property,
            temp3->Size_of_the_infrastructure, temp3->Floor, temp3->Size_of_the_main_land, temp3->number_of_the_owner, temp3->Number_of_bedrooms, temp3->mortgage, temp3->Rent, &temp3->isActive) != 13)
        {
            free(temp3);
            break;
        }
        if (first3 == NULL)
        {
            first3 = temp3;
            last3 = first3;
            last3->next = NULL;
        }
        else
        {
            last3->next = temp3;
            last3 = temp3;
            last3->next = NULL;
        }
    }
    temp3 = first3;
    while(temp3 != NULL)
    {
        while(atoi(temp3->Size_of_the_infrastructure) >= atoi(infrastructure1) && atoi(temp3->Size_of_the_infrastructure) <= atoi(infrastructure2) && temp3->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY RENT\n\n", number3_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp3->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp3->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp3->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp3->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp3->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp3->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp3->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp3->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp3->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp3->Number_of_bedrooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp3->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp3->Rent);
            number3_property++;
            break;
        }
        temp3 = temp3->next;
    }

    fclose(file3);

    temp3 = first3;
    while(temp3 != NULL)
    {
        struct Residential_property_information_for_rent *next = temp3->next;
        free(temp3);
        temp3 = next;
    }

    if(number3_property == 1)
    {
        printf("\e[31mThe specified residential property rent does not exist\e[m\n\n");
    }


    //OFFICE_RENTTTTTTTT

    printf("\e[36m******************************************************\e[m\n\n");
    int number4_property = 1;
    FILE* file4;
    file4 = fopen("Office_property_information_for_rent.txt", "r+");
    struct Office_property_information_for_rent *first4 = NULL;
    struct Office_property_information_for_rent *last4 = NULL;
    struct Office_property_information_for_rent* temp4;

    if (file4 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        struct Office_property_information_for_rent* temp4 = malloc(sizeof(struct Office_property_information_for_rent));
        if(fscanf(file4, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp4->propertyID, temp4->Municipal_area, temp4->Exact_address, temp4->Property_Type, temp4->Age_of_the_property,
            temp4->Size_of_the_infrastructure, temp4->Floor, temp4->Size_of_the_main_land, temp4->number_of_the_owner, temp4->Number_of_office_rooms, temp4->mortgage, temp4->Rent, &temp4->isActive) != 13)
        {
            free(temp4);
            break;
        }
        if (first4 == NULL)
        {
            first4 = temp4;
            last4 = first4;
            last4->next = NULL;
        }
        else
        {
            last4->next = temp4;
            last4 = temp4;
            last4->next = NULL;
        }
    }
    temp4 = first4;
    while(temp4 != NULL)
    {
        while(atoi(temp4->Size_of_the_infrastructure) >= atoi(infrastructure1) && atoi(temp4->Size_of_the_infrastructure) <= atoi(infrastructure2) && temp4->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY RENT\n\n", number4_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp4->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp4->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp4->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp4->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp4->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp4->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp4->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp4->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp4->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp4->Number_of_office_rooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp4->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp4->Rent);
            number4_property++;
            break;
        }
        temp4 = temp4->next;
    }

    fclose(file4);

    temp4 = first4;
    while(temp4 != NULL)
    {
        struct Office_property_information_for_rent *next = temp4->next;
        free(temp4);
        temp4 = next;
    }

    if(number4_property == 1)
    {
        printf("\e[31mThe specified office property rent does not exist\e[m\n\n");
    }


    //land_renttttttttttttttt


    printf("\e[36m******************************************************\e[m\n\n");
    int number5_property = 1;
    FILE* file5;
    file5 = fopen("Land_rent_information.txt", "r+");
    struct Land_rent_information *first5 = NULL;
    struct Land_rent_information *last5 = NULL;
    struct Land_rent_information* temp5;

    if (file5 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        struct Land_rent_information* temp5 = malloc(sizeof(struct Land_rent_information));
        if(fscanf(file5, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp5->propertyID, temp5->Municipal_area, temp5->Exact_address, temp5->land_Type, temp5->Size_of_the_land,
                temp5->number_of_the_owner, temp5->mortgage, temp5->Rent, &temp5->isActive) != 9)
        {
            free(temp5);
            break;
        }
        if(first5 == NULL)
        {
            first5 = temp5;
            last5 = first5;
            last5->next = NULL;
        }
        else
        {
            last5->next = temp5;
            last5 = temp5;
            last5->next = NULL;
        }
    }

    temp5 = first5;
    while(temp5 != NULL)
    {
        while(atoi(temp5->Size_of_the_land) >= atoi(infrastructure1) && atoi(temp5->Size_of_the_land) <= atoi(infrastructure2) && temp5->isActive == 1)
        {
            printf("%d.LAND RENT\n\n", number5_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp5->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp5->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp5->Exact_address);
            printf("Type of land: \e[4m\e[33m%s\e[m\e[m\n", temp5->land_Type);
            printf("Size of the land: \e[4m\e[33m%s\e[m\e[m\n", temp5->Size_of_the_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp5->number_of_the_owner);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp5->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp5->Rent);
            number5_property++;
            break;
        }
        temp5 = temp5->next;
    }

    fclose(file5);

    temp5 = first5;
    while(temp5 != NULL)
    {
        struct Land_rent_information *next = temp5->next;
        free(temp5);
        temp5 = next;
    }

    if (number5_property == 1)
    {
        printf("\e[31mThe specified land rent does not exist\e[m\n\n");
    }

    printf("\e[36m******************************************************\e[m\n\n");
    printf("Press any key for back to the previous menu...");
    getch();
    system("cls");
    reports();

}
void properties_special_price(void)
{
    char price1[30] , price2[30];
    int number_property = 1;
    FILE* file;
    file = fopen("Residential_property_information_for_sale.txt", "r+");
    struct Residential_property_information_for_sale *first = NULL;
    struct Residential_property_information_for_sale *last = NULL;
    struct Residential_property_information_for_sale* temp;

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while(1)
    {
        int a = 0;
        printf("Enter the lowest price considered: ");//کمترین قیمت مدنظر
        fgets(price1, sizeof(price1), stdin);
        price1[strcspn(price1, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(price1); i++)
        {
            if(isdigit(price1[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    while(1)
    {
        int a = 0;
        printf("Enter the highest price considered: ");
        fgets(price2, sizeof(price2), stdin);
        price2[strcspn(price2, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(price2); i++)
        {
            if(isdigit(price2[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    printf("\n");
    printf("\e[36m******************************************************\e[m\n\n");

    while(1)
    {
       struct Residential_property_information_for_sale* temp = malloc(sizeof(struct Residential_property_information_for_sale));
        if(fscanf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
            temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_bedrooms, temp->Price, &temp->isActive) != 12)
        {
            free(temp);
            break;
        }
        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;
    while(temp != NULL)
    {
        while(atoi(temp->Price) >= atoi(price1) && atoi(temp->Price) <= atoi(price2) && temp->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY SALE\n\n", number_property);
            printf("PopertyID: \e[4m\e[33m%s\e[m\e[m\n", temp->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp->Number_of_bedrooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp->Price);
            number_property++;
            break;

        }
        temp = temp->next;
    }
    fclose(file);

    temp = first;
    while(temp != NULL)
    {
        struct Residential_property_information_for_sale *next = temp->next;
        free(temp);
        temp = next;
    }

    if (number_property == 1)
    {
        printf("\e[31mThe specified residential property sale does not exist\e[m\n\n");
    }



    printf("\e[36m******************************************************\e[m\n\n");
    int number1_property = 1;
    FILE* file1;
    file1 = fopen("Office_property_information_for_sale.txt", "r+");
    struct Office_property_information_for_sale *first1 = NULL;
    struct Office_property_information_for_sale *last1 = NULL;
    struct Office_property_information_for_sale* temp1;

    if (file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while (1)
    {
        struct Office_property_information_for_sale* temp1 = malloc(sizeof(struct Office_property_information_for_sale));
        if (fscanf(file1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d", temp1->propertyID, temp1->Municipal_area, temp1->Exact_address, temp1->Property_Type, temp1->Age_of_the_property,
            temp1->Size_of_the_infrastructure, temp1->Floor, temp1->Size_of_the_main_land, temp1->number_of_the_owner, temp1->Number_of_office_rooms, temp1->Price, &temp1->isActive) != 12)
        {
            free(temp1);
            break;
        }
        if (first1 == NULL)
        {
            first1 = temp1;
            last1 = first1;
            last1->next = NULL;
        }
        else
        {
            last1->next = temp1;
            last1 = temp1;
            last1->next = NULL;
        }
    }
    temp1 = first1;
    while (temp1 != NULL)
    {
        while (atoi(temp1->Price) >= atoi(price1) && atoi(temp1->Price) <= atoi(price2) && temp1->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY SALE\n\n", number1_property);
            printf("PopertyID: \e[4m\e[33m%s\e[m\e[m\n", temp1->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp1->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp1->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp1->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp1->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp1->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp1->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp1->Number_of_office_rooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp1->Price);
            number1_property++;
            break;
        }
        temp1 = temp1->next;
    }
    fclose(file1);

    temp1 = first1;
    while (temp1 != NULL)
    {
        struct Office_property_information_for_sale *next = temp1->next;
        free(temp1);
        temp1 = next;
    }

    if (number1_property == 1)
    {
        printf("\e[31mThe specified office property sale does not exist\e[m\n\n");
    }


    printf("\e[36m******************************************************\e[m\n\n");
    int number2_property = 1;
    FILE* file2;
    file2 = fopen("Land_sales_information.txt", "r+");
    struct Land_sales_information *first2 = NULL;
    struct Land_sales_information *last2 = NULL;
    struct Land_sales_information* temp2;

    if(file2 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
    struct Land_sales_information* temp2 = malloc(sizeof(struct Land_sales_information));
        if(fscanf(file2, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp2->propertyID, temp2->Municipal_area, temp2->Exact_address, temp2->land_Type, temp2->Size_of_the_land,
                temp2->number_of_the_owner, temp2->Price, &temp2->isActive) != 8)
        {
            free(temp2);
            break;
        }
        if(first2 == NULL)
        {
            first2 = temp2;
            last2 = first2;
            last2->next = NULL;
        }
        else
        {
            last2->next = temp2;
            last2 = temp2;
            last2->next = NULL;
        }
    }

    temp2 = first2;
    while(temp2 != NULL)
    {
        while(atoi(temp2->Price) >= atoi(price1) && atoi(temp2->Price) <= atoi(price2) && temp2->isActive == 1)
        {
                printf("%d.LAND SALE\n\n", number2_property);
                printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp2->propertyID);
                printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp2->Municipal_area);
                printf("Address: \e[33m%s\e[m\n", temp2->Exact_address);
                printf("Type of land: \e[4m\e[33m%s\e[m\e[m\n", temp2->land_Type);
                printf("Size of the land: \e[4m\e[33m%s\e[m\e[m\n", temp2->Size_of_the_land);
                printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp2->number_of_the_owner);
                printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp2->Price);
                number2_property++;
                break;
        }
        temp2 = temp2->next;
    }

    fclose(file2);

    temp2 = first2;
    while(temp2 != NULL)
    {
        struct Land_sales_information *next = temp2->next;
        free(temp2);
        temp2 = next;
    }

    if (number2_property == 1)
    {
            printf("\e[31mThe specified land sale does not exist\e[m\n\n");
    }

    printf("\e[36m******************************************************\e[m\n\n");
    printf("Press any key for back to the previous menu...");
    getch();
    system("cls");
    reports();
}
void residential_properties_specific_number_of_bedrooms(void)
{
    char bed_room[30];
    int number_property = 1;
    FILE* file;
    file = fopen("Residential_property_information_for_sale.txt", "r+");
    struct Residential_property_information_for_sale *first = NULL;
    struct Residential_property_information_for_sale *last = NULL;
    struct Residential_property_information_for_sale* temp;

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while(1)
    {
        int a = 0;
        printf("Enter the number of bedrooms what you want: ");
        fgets(bed_room, sizeof(bed_room), stdin);
        bed_room[strcspn(bed_room, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(bed_room); i++)
        {
            if(isdigit(bed_room[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    printf("\n");
    printf("\e[36m******************************************************\e[m\n\n");
    while(1)
    {
       struct Residential_property_information_for_sale* temp = malloc(sizeof(struct Residential_property_information_for_sale));
        if(fscanf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
            temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_bedrooms, temp->Price, &temp->isActive) != 12)
        {
            free(temp);
            break;
        }
        if (first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }

    temp = first;
    while(temp != NULL)
    {
        while(atoi(temp->Number_of_bedrooms) == atoi(bed_room) && temp->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY SALE\n\n", number_property);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp->Number_of_bedrooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp->Price);
            number_property++;
            break;
        }
        temp = temp->next;
    }

    fclose(file);

    temp = first;
    while(temp != NULL)
    {
        struct Residential_property_information_for_sale *next = temp->next;
        free(temp);
        temp = next;
    }

    if (number_property == 1)
    {
        printf("\e[31mThe specified residential property sale does not exist\e[m\n\n");
    }

    printf("\e[36m******************************************************\e[m\n\n");
    int number1_property = 1;
    FILE* file1;
    file1 = fopen("Residential_property_information_for_rent.txt", "r+");
    struct Residential_property_information_for_rent *first1 = NULL;
    struct Residential_property_information_for_rent *last1 = NULL;
    struct Residential_property_information_for_rent* temp1;

    if (file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        struct Residential_property_information_for_rent* temp1 = malloc(sizeof(struct Residential_property_information_for_rent));
        if(fscanf(file1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp1->propertyID, temp1->Municipal_area, temp1->Exact_address, temp1->Property_Type, temp1->Age_of_the_property,
            temp1->Size_of_the_infrastructure, temp1->Floor, temp1->Size_of_the_main_land, temp1->number_of_the_owner, temp1->Number_of_bedrooms, temp1->mortgage, temp1->Rent, &temp1->isActive) != 13)
        {
            free(temp1);
            break;
        }
        if (first1 == NULL)
        {
            first1 = temp1;
            last1 = first1;
            last1->next = NULL;
        }
        else
        {
            last1->next = temp1;
            last1 = temp1;
            last1->next = NULL;
        }
    }

    temp1 = first1;
    while(temp1 != NULL)
    {
        while(atoi(temp1->Number_of_bedrooms) == atoi(bed_room) && temp1->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY RENT\n\n", number1_property);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp1->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp1->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp1->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp1->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp1->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp1->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp1->Number_of_bedrooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp1->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp1->Rent);
            number1_property++;
            break;
        }
        temp1 = temp1->next;
    }

    fclose(file1);

    temp1 = first1;
    while(temp1 != NULL)
    {
        struct Residential_property_information_for_rent *next1 = temp1->next;
        free(temp1);
        temp1 = next1;
    }

    if (number1_property == 1)
    {
        printf("\e[31mThe specified residential property rent does not exist\e[m\n\n");

    }

    printf("\e[36m******************************************************\e[m\n\n");
        printf("Press any key for back to the previous menu...");
        getch();
        system("cls");
        reports();
}
void office_properties_specific_number_of_rooms(void)
{

}
void rental_properties_specific_limits_for_mortgage_and_rent(void)
{
    char mortgage1[30], mortgage2[30], rent1[30], rent2[30];
    int number3_property = 1;
    FILE* file3;
    file3 = fopen("Residential_property_information_for_rent.txt", "r+");
    struct Residential_property_information_for_rent *first3 = NULL;
    struct Residential_property_information_for_rent *last3 = NULL;
    struct Residential_property_information_for_rent* temp3;

    if (file3 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while(1)
    {
        int a = 0;
        printf("The minimum amount of the mortgage in question: ");
        fgets(mortgage1, sizeof(mortgage1), stdin);
        mortgage1[strcspn(mortgage1, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(mortgage1); i++)
        {
            if(isdigit(mortgage1[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }
    while(1)
    {
        int a = 0;
        printf("The maximum amount of the mortgage in question: ");
        fgets(mortgage2, sizeof(mortgage2), stdin);
        mortgage2[strcspn(mortgage2, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(mortgage2); i++)
        {
            if(isdigit(mortgage2[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }
    while(1)
    {
        int a = 0;
        printf("The minimum amount of the rent in question: ");
        fgets(rent1, sizeof(rent1), stdin);
        rent1[strcspn(rent1, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(rent1); i++)
        {
            if(isdigit(rent1[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }
    while(1)
    {
        int a = 0;
        printf("The maximum amount of the rent in question: ");
        fgets(rent2, sizeof(rent2), stdin);
        rent2[strcspn(rent2, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(rent2); i++)
        {
            if(isdigit(rent2[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

        printf("\n");
        printf("\e[36m******************************************************\e[m\n\n");
    while(1)
    {
    struct Residential_property_information_for_rent* temp3 = malloc(sizeof(struct Residential_property_information_for_rent));
        if(fscanf(file3, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp3->propertyID, temp3->Municipal_area, temp3->Exact_address, temp3->Property_Type, temp3->Age_of_the_property,
            temp3->Size_of_the_infrastructure, temp3->Floor, temp3->Size_of_the_main_land, temp3->number_of_the_owner, temp3->Number_of_bedrooms, temp3->mortgage, temp3->Rent, &temp3->isActive) != 13)
        {
            free(temp3);
            break;
        }
        if (first3 == NULL)
        {
            first3 = temp3;
            last3 = first3;
            last3->next = NULL;
        }
        else
        {
            last3->next = temp3;
            last3 = temp3;
            last3->next = NULL;
        }
    }
    temp3 = first3;
    while(temp3 != NULL)
    {
        while(atoi(temp3->mortgage) >= atoi(mortgage1) && atoi(temp3->mortgage) <= atoi(mortgage2) && atoi(temp3->Rent) >= atoi(rent1) && atoi(temp3->Rent) <= atoi(rent2) && temp3->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY RENT\n\n", number3_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp3->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp3->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp3->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp3->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp3->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp3->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp3->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp3->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp3->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp3->Number_of_bedrooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp3->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp3->Rent);
            number3_property++;
            break;
        }
        temp3 = temp3->next;
    }

    fclose(file3);

    temp3 = first3;
    while(temp3 != NULL)
    {
        struct Residential_property_information_for_rent *next = temp3->next;
        free(temp3);
        temp3 = next;
    }

    if(number3_property == 1)
    {
        printf("\e[31mThe specified residential property rent does not exist\e[m\n\n");
    }


    //OFFICE_RENTTTTTTTT

    printf("\e[36m******************************************************\e[m\n\n");
    int number4_property = 1;
    FILE* file4;
    file4 = fopen("Office_property_information_for_rent.txt", "r+");
    struct Office_property_information_for_rent *first4 = NULL;
    struct Office_property_information_for_rent *last4 = NULL;
    struct Office_property_information_for_rent* temp4;

    if (file4 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        struct Office_property_information_for_rent* temp4 = malloc(sizeof(struct Office_property_information_for_rent));
        if(fscanf(file4, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp4->propertyID, temp4->Municipal_area, temp4->Exact_address, temp4->Property_Type, temp4->Age_of_the_property,
            temp4->Size_of_the_infrastructure, temp4->Floor, temp4->Size_of_the_main_land, temp4->number_of_the_owner, temp4->Number_of_office_rooms, temp4->mortgage, temp4->Rent, &temp4->isActive) != 13)
        {
            free(temp4);
            break;
        }
        if (first4 == NULL)
        {
            first4 = temp4;
            last4 = first4;
            last4->next = NULL;
        }
        else
        {
            last4->next = temp4;
            last4 = temp4;
            last4->next = NULL;
        }
    }
    temp4 = first4;
    while(temp4 != NULL)
    {
        while(atoi(temp4->mortgage) >= atoi(mortgage1) && atoi(temp4->mortgage) <= atoi(mortgage2) && atoi(temp4->Rent) >= atoi(rent1) && atoi(temp4->Rent) <= atoi(rent2) && temp4->isActive == 1)
        {
            printf("%d.OFFICE PROPERTY RENT\n\n", number4_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp4->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp4->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp4->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp4->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp4->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp4->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp4->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp4->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp4->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp4->Number_of_office_rooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp4->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp4->Rent);
            number4_property++;
            break;
        }
        temp4 = temp4->next;
    }

    fclose(file4);

    temp4 = first4;
    while(temp4 != NULL)
    {
        struct Office_property_information_for_rent *next = temp4->next;
        free(temp4);
        temp4 = next;
    }

    if(number4_property == 1)
    {
        printf("\e[31mThe specified office property rent does not exist\e[m\n\n");
    }


    //land_renttttttttttttttt


    printf("\e[36m******************************************************\e[m\n\n");
    int number5_property = 1;
    FILE* file5;
    file5 = fopen("Land_rent_information.txt", "r+");
    struct Land_rent_information *first5 = NULL;
    struct Land_rent_information *last5 = NULL;
    struct Land_rent_information* temp5;

    if (file5 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while(1)
    {
        struct Land_rent_information* temp5 = malloc(sizeof(struct Land_rent_information));
        if(fscanf(file5, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp5->propertyID, temp5->Municipal_area, temp5->Exact_address, temp5->land_Type, temp5->Size_of_the_land,
                temp5->number_of_the_owner, temp5->mortgage, temp5->Rent, &temp5->isActive) != 9)
        {
            free(temp5);
            break;
        }
        if(first5 == NULL)
        {
            first5 = temp5;
            last5 = first5;
            last5->next = NULL;
        }
        else
        {
            last5->next = temp5;
            last5 = temp5;
            last5->next = NULL;
        }
    }

    temp5 = first5;
    while(temp5 != NULL)
    {
        while(atoi(temp5->mortgage) >= atoi(mortgage1) && atoi(temp5->mortgage) <= atoi(mortgage2) && atoi(temp5->Rent) >= atoi(rent1) && atoi(temp5->Rent) <= atoi(rent2) && temp5->isActive == 1)
        {
            printf("%d.LAND RENT\n\n", number5_property);
            printf("PropertyID: \e[4m\e[33m%s\e[m\e[m\n", temp5->propertyID);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp5->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp5->Exact_address);
            printf("Type of land: \e[4m\e[33m%s\e[m\e[m\n", temp5->land_Type);
            printf("Size of the land: \e[4m\e[33m%s\e[m\e[m\n", temp5->Size_of_the_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp5->number_of_the_owner);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp5->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp5->Rent);
            number5_property++;
            break;
        }
        temp5 = temp5->next;
    }

    fclose(file5);

    temp5 = first5;
    while(temp5 != NULL)
    {
        struct Land_rent_information *next = temp5->next;
        free(temp5);
        temp5 = next;
    }

    if (number5_property == 1)
    {
        printf("\e[31mThe specified land rent does not exist\e[m\n\n");
    }

    printf("\e[36m******************************************************\e[m\n\n");
    printf("Press any key for back to the previous menu...");
    getch();
    system("cls");
    reports();

}
void Residential_apartments_in_particular_floor(void)
{
    char floor[30];
    int number_property = 1;
    FILE* file;
    file = fopen("Residential_property_information_for_sale.txt", "r+");
    struct Residential_property_information_for_sale *first = NULL;
    struct Residential_property_information_for_sale *last = NULL;
    struct Residential_property_information_for_sale* temp;

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while(1)
    {
        int a = 0;
        printf("Enter the floor of Residential apartment what you want: ");
        fgets(floor, sizeof(floor), stdin);
        floor[strcspn(floor, "\n")] = '\0';  // حذف کاراکتر \n
        for(int i = 0; i < strlen(floor); i++)
        {
            if(isdigit(floor[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    printf("\n");
    printf("\e[36m******************************************************\e[m\n\n");

    while(1)
    {
        struct Residential_property_information_for_sale* temp = malloc(sizeof(struct Residential_property_information_for_sale));
        if(fscanf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
            temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_bedrooms, temp->Price, &temp->isActive) != 12)
        {
            free(temp);
            break;
        }

        // تبدیل property_type به حروف کوچک
        for (int i = 0; temp->Property_Type[i]; i++)
        {
            temp->Property_Type[i] = tolower(temp->Property_Type[i]);
        }

        if (strcmp(temp->Property_Type, "apartment") == 0 && atoi(temp->Floor) == atoi(floor) && temp->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY SALE\n\n", number_property);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp->Number_of_bedrooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp->Price);
            number_property++;
        }

        temp = temp->next;
    }

    fclose(file);

    temp = first;
    while(temp != NULL)
    {
        struct Residential_property_information_for_sale *next = temp->next;
        free(temp);
        temp = next;
    }

    if (number_property == 1)
    {
        printf("\e[31mThe specified residential property sale does not exist\e[m\n\n");
    }



    printf("\e[36m******************************************************\e[m\n\n");
    int number1_property = 1;
    FILE* file1;
    file1 = fopen("Residential_property_information_for_rent.txt", "r+");
    struct Residential_property_information_for_rent *first1 = NULL;
    struct Residential_property_information_for_rent *last1 = NULL;
    struct Residential_property_information_for_rent* temp1;

    if (file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while (1)
    {
        struct Residential_property_information_for_rent* temp1 = malloc(sizeof(struct Residential_property_information_for_rent));
        if (fscanf(file1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d", temp1->propertyID, temp1->Municipal_area, temp1->Exact_address, temp1->Property_Type, temp1->Age_of_the_property,
            temp1->Size_of_the_infrastructure, temp1->Floor, temp1->Size_of_the_main_land, temp1->number_of_the_owner, temp1->Number_of_bedrooms, temp1->mortgage, temp1->Rent, &temp1->isActive) != 13)
        {
            free(temp1);
            break;
        }

        for (int i = 0; temp1->Property_Type[i]; i++)
        {
            temp1->Property_Type[i] = tolower(temp1->Property_Type[i]);
        }

        if (strcmp(temp1->Property_Type, "apartment") == 0 && atoi(temp1->Floor) == atoi(floor) && temp1->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY RENT\n\n", number1_property);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp1->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp1->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp1->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp1->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp1->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp1->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp1->Number_of_bedrooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp1->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp1->Rent);
            number1_property++;
        }

        temp1 = temp1->next;
    }

    fclose(file1);

    temp1 = first1;
    while (temp1 != NULL)
    {
        struct Residential_property_information_for_rent* next = temp1->next;
        free(temp1);
        temp1 = next;
    }

    if (number1_property == 1)
    {
        printf("\e[31mThe specified residential property rent does not exist\e[m\n\n");
    }
    printf("\e[36m******************************************************\e[m\n\n");
    printf("Press any key for back to the previous menu...");
    getch();
    system("cls");
    reports();
}
void office_apartments_in_particular_floor(void)
{
    char floor[30];
    int number_property = 1;
    FILE* file;
    file = fopen("Residential_property_information_for_sale.txt", "r+");
    struct Residential_property_information_for_sale *first = NULL;
    struct Residential_property_information_for_sale *last = NULL;
    struct Residential_property_information_for_sale* temp;

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    while(1)
    {
        int a = 0;
        printf("Enter the floor of Residential apartment what you want: ");
        scanf("%s", floor);
        getchar();
        for(int i = 0; i < strlen(floor); i++)
        {
            if(isdigit(floor[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    printf("\n");
    printf("\e[36m******************************************************\e[m\n\n");

    while(1)
    {
        struct Residential_property_information_for_sale* temp = malloc(sizeof(struct Residential_property_information_for_sale));
        if(fscanf(file, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d",temp->propertyID, temp->Municipal_area, temp->Exact_address, temp->Property_Type, temp->Age_of_the_property,
            temp->Size_of_the_infrastructure, temp->Floor, temp->Size_of_the_main_land, temp->number_of_the_owner, temp->Number_of_bedrooms, temp->Price, &temp->isActive) != 12)
        {
            free(temp);
            break;
        }

        // تبدیل property_type به حروف کوچک
        for (int i = 0; temp->Property_Type[i]; i++)
        {
            temp->Property_Type[i] = tolower(temp->Property_Type[i]);
        }

        if (strcmp(temp->Property_Type, "apartment") == 0 && atoi(temp->Floor) == atoi(floor) && temp->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY SALE\n\n", number_property);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp->Number_of_bedrooms);
            printf("Price: \e[4m\e[33m%s\e[m\e[m\n\n", temp->Price);
            number_property++;
        }

        temp = temp->next;
    }

    fclose(file);

    temp = first;
    while(temp != NULL)
    {
        struct Residential_property_information_for_sale *next = temp->next;
        free(temp);
        temp = next;
    }

    if (number_property == 1)
    {
        printf("\e[31mThe specified residential property sale does not exist\e[m\n\n");
    }



    printf("\e[36m******************************************************\e[m\n\n");
    int number1_property = 1;
    FILE* file1;
    file1 = fopen("Residential_property_information_for_rent.txt", "r+");
    struct Residential_property_information_for_rent *first1 = NULL;
    struct Residential_property_information_for_rent *last1 = NULL;
    struct Residential_property_information_for_rent* temp1;

    if (file1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while (1)
    {
        struct Residential_property_information_for_rent* temp1 = malloc(sizeof(struct Residential_property_information_for_rent));
        if (fscanf(file1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d", temp1->propertyID, temp1->Municipal_area, temp1->Exact_address, temp1->Property_Type, temp1->Age_of_the_property,
            temp1->Size_of_the_infrastructure, temp1->Floor, temp1->Size_of_the_main_land, temp1->number_of_the_owner, temp1->Number_of_bedrooms, temp1->mortgage, temp1->Rent, &temp1->isActive) != 13)
        {
            free(temp1);
            break;
        }

        for (int i = 0; temp1->Property_Type[i]; i++)
        {
            temp1->Property_Type[i] = tolower(temp1->Property_Type[i]);
        }

        if (strcmp(temp1->Property_Type, "apartment") == 0 && atoi(temp1->Floor) == atoi(floor) && temp1->isActive == 1)
        {
            printf("%d.RESIDENTIAL PROPERTY RENT\n\n", number1_property);
            printf("Municipal area: \e[4m\e[33m%s\e[m\e[m\n", temp1->Municipal_area);
            printf("Address: \e[33m%s\e[m\n", temp1->Exact_address);
            printf("Age of the property: \e[4m\e[33m%s\e[m\e[m\n", temp1->Age_of_the_property);
            printf("Floor: \e[4m\e[33m%s\e[m\e[m\n", temp1->Floor);
            printf("Property Type: \e[4m\e[33m%s\e[m\e[m\n", temp1->Property_Type);
            printf("Size of the infrastructure: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_infrastructure);
            printf("Size of the main land: \e[4m\e[33m%s\e[m\e[m\n", temp1->Size_of_the_main_land);
            printf("Phone Number: \e[4m\e[33m%s\e[m\e[m\n", temp1->number_of_the_owner);
            printf("Bedroom: \e[4m\e[33m%s\e[m\e[m\n", temp1->Number_of_bedrooms);
            printf("Mortgage: \e[4m\e[33m%s\e[m\e[m\n", temp1->mortgage);
            printf("Rent: \e[4m\e[33m%s\e[m\e[m\n\n", temp1->Rent);
            number1_property++;
        }

        temp1 = temp1->next;
    }

    fclose(file1);

    temp1 = first1;
    while (temp1 != NULL)
    {
        struct Residential_property_information_for_rent* next = temp1->next;
        free(temp1);
        temp1 = next;
    }

    if (number1_property == 1)
    {
        printf("\e[31mThe specified residential property rent does not exist\e[m\n\n");
    }
    printf("\e[36m******************************************************\e[m\n\n");
    printf("Press any key for back to the previous menu...");
    getch();
    system("cls");
    reports();
}
void settings(void)
{
    char passwordd[30];
    char new_name[30];
    char new_last_name[30];
    char new_id[30];
    char new_postal[30];
    char new_mobile_number[30];
    char new_email[30];
    char new_passwordd[30];
    int choice_setting;
    struct Sign_Up_information *first = NULL;
    struct Sign_Up_information *last = NULL;
    struct Sign_Up_information *temp;
    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("Profile_user_sign_up.txt", "r");
    if(fp1 == NULL)
    {
        printf("\e[31mERROR opening Profile_user_sign_up.txt file.\e[m\n");
        exit(1);
    }
    while(1)
    {
        temp = malloc(sizeof(struct Sign_Up_information));
        if(fscanf(fp1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n" , temp->Name, temp->Last_name, temp->Postal_code, temp->Username, temp->ID,
                  temp->Mobile_number, temp->Email, temp->Password1) != 8)
        {
            break;
        }
        if(first == NULL)
        {
            first = temp;
            last = first;
            last->next = NULL;
        }
        else
        {
            last->next = temp;
            last = temp;
            last->next = NULL;
        }
    }
    temp = first;

    printf("To change information, please enter your password: ");
    scanf("%s", passwordd);
    getchar();
    system("cls");
    while(temp != NULL)
    {
        if (strcmp(temp->Password1, passwordd) == 0)
        {
            printf("\e[32mLogin was successful!\e[m");
            Sleep(2000);
            system("cls");
            printf("\e[4m1\e[m. Name change\n\n");
            printf("\e[4m2\e[m. Last name change\n\n");
            printf("\e[4m3\e[m. ID\n\n");
            printf("\e[4m4\e[m. Postal code change\n\n");
            printf("\e[4m5\e[m. Mobile number\n\n");
            printf("\e[4m6\e[m. Email\n\n");
            printf("\e[4m7\e[m. Password\n\n");
            printf("\e[4m8\e[m. Back to the previous menu\n\n");
            printf("\e[5m>>>Please Enter Your Choice: \e[m");
            scanf("%d", &choice_setting);
            getchar();
            system("cls");
            switch(choice_setting)
            {
                case 1:
                    {
                        printf("Enter your new first name: ");
                        scanf("%s", new_name);
                        getchar();
                        strcpy(temp->Name, new_name);
                        fp2 = fopen("temp.txt", "w");
                        if (fp2 == NULL)
                        {
                            printf("[MEMORY ALLOCATION FAILED]\n");
                            exit(1);
                        }
                        temp = first;
                        while(temp != NULL)
                        {
                            fprintf(fp2, "%s\n", temp->Name);
                            fprintf(fp2, "%s\n", temp->Last_name);
                            fprintf(fp2, "%s\n", temp->Postal_code);
                            fprintf(fp2, "%s\n", temp->Username);
                            fprintf(fp2, "%s\n", temp->ID);
                            fprintf(fp2, "%s\n", temp->Mobile_number);
                            fprintf(fp2, "%s\n", temp->Email);
                            fprintf(fp2, "%s\n", temp->Password1);
                            temp = temp->next;
                        }
                        fclose(fp1);
                        fclose(fp2);
                        remove("Profile_user_sign_up.txt");
                        rename("temp.txt", "Profile_user_sign_up.txt");
                        printf("\e[32mChanges saved successfully\e[m");
                        Sleep(2000);
                        system("cls");
                        settings();
                        break;

                    }


                case 2:
                    {
                        printf("Enter your new last name: ");
                        scanf("%s", new_last_name);
                        getchar();
                        strcpy(temp->Last_name, new_last_name);
                        fp2 = fopen("temp.txt", "w");
                        if (fp2 == NULL)
                        {
                            printf("[MEMORY ALLOCATION FAILED]\n");
                            exit(1);
                        }
                        temp = first;
                        while(temp != NULL)
                        {
                            fprintf(fp2, "%s\n", temp->Name);
                            fprintf(fp2, "%s\n", temp->Last_name);
                            fprintf(fp2, "%s\n", temp->Postal_code);
                            fprintf(fp2, "%s\n", temp->Username);
                            fprintf(fp2, "%s\n", temp->ID);
                            fprintf(fp2, "%s\n", temp->Mobile_number);
                            fprintf(fp2, "%s\n", temp->Email);
                            fprintf(fp2, "%s\n", temp->Password1);
                            temp = temp->next;
                        }
                        fclose(fp1);
                        fclose(fp2);
                        remove("Profile_user_sign_up.txt");
                        rename("temp.txt", "Profile_user_sign_up.txt");
                        printf("\e[32mChanges saved successfully\e[m");
                        Sleep(2000);
                        system("cls");
                        settings();
                        break;
                    }



                case 3:
                    {
                        printf("Enter your new ID: ");
                        scanf("%s", new_id);
                        getchar();
                        strcpy(temp->ID, new_id);
                        fp2 = fopen("temp.txt", "w");
                        if (fp2 == NULL)
                        {
                            printf("[MEMORY ALLOCATION FAILED]\n");
                            exit(1);
                        }
                        temp = first;
                        while(temp != NULL)
                        {
                            fprintf(fp2, "%s\n", temp->Name);
                            fprintf(fp2, "%s\n", temp->Last_name);
                            fprintf(fp2, "%s\n", temp->Postal_code);
                            fprintf(fp2, "%s\n", temp->Username);
                            fprintf(fp2, "%s\n", temp->ID);
                            fprintf(fp2, "%s\n", temp->Mobile_number);
                            fprintf(fp2, "%s\n", temp->Email);
                            fprintf(fp2, "%s\n", temp->Password1);
                            temp = temp->next;
                        }
                        fclose(fp1);
                        fclose(fp2);
                        remove("Profile_user_sign_up.txt");
                        rename("temp.txt", "Profile_user_sign_up.txt");
                        printf("\e[32mChanges saved successfully\e[m");
                        Sleep(2000);
                        system("cls");
                        settings();
                        break;
                    }


                case 4:
                    {
                        printf("Enter your new postal code: ");
                        scanf("%s", new_postal);
                        getchar();
                        strcpy(temp->Postal_code, new_postal);
                        fp2 = fopen("temp.txt", "w");
                        if (fp2 == NULL)
                        {
                            printf("[MEMORY ALLOCATION FAILED]\n");
                            exit(1);
                        }
                        temp = first;
                        while(temp != NULL)
                        {
                            fprintf(fp2, "%s\n", temp->Name);
                            fprintf(fp2, "%s\n", temp->Last_name);
                            fprintf(fp2, "%s\n", temp->Postal_code);
                            fprintf(fp2, "%s\n", temp->Username);
                            fprintf(fp2, "%s\n", temp->ID);
                            fprintf(fp2, "%s\n", temp->Mobile_number);
                            fprintf(fp2, "%s\n", temp->Email);
                            fprintf(fp2, "%s\n", temp->Password1);
                            temp = temp->next;
                        }
                        fclose(fp1);
                        fclose(fp2);
                        remove("Profile_user_sign_up.txt");
                        rename("temp.txt", "Profile_user_sign_up.txt");
                        printf("\e[32mChanges saved successfully\e[m");
                        Sleep(2000);
                        system("cls");
                        settings();
                        break;
                    }


                case 5:
                    {
                        printf("Enter your new Mobile number: ");
                        scanf("%s", new_mobile_number);
                        getchar();
                        strcpy(temp->Mobile_number, new_mobile_number);
                        fp2 = fopen("temp.txt", "w");
                        if (fp2 == NULL)
                        {
                            printf("[MEMORY ALLOCATION FAILED]\n");
                            exit(1);
                        }
                        temp = first;
                        while(temp != NULL)
                        {
                            fprintf(fp2, "%s\n", temp->Name);
                            fprintf(fp2, "%s\n", temp->Last_name);
                            fprintf(fp2, "%s\n", temp->Postal_code);
                            fprintf(fp2, "%s\n", temp->Username);
                            fprintf(fp2, "%s\n", temp->ID);
                            fprintf(fp2, "%s\n", temp->Mobile_number);
                            fprintf(fp2, "%s\n", temp->Email);
                            fprintf(fp2, "%s\n", temp->Password1);
                            temp = temp->next;
                        }
                        fclose(fp1);
                        fclose(fp2);
                        remove("Profile_user_sign_up.txt");
                        rename("temp.txt", "Profile_user_sign_up.txt");
                        printf("\e[32mChanges saved successfully\e[m");
                        Sleep(2000);
                        system("cls");
                        settings();
                        break;
                    }


                case 6:
                    {
                        printf("Enter your new Email: ");
                        scanf("%s", new_email);
                        getchar();
                        strcpy(temp->Email, new_email);
                        fp2 = fopen("temp.txt", "w");
                        if (fp2 == NULL)
                        {
                            printf("[MEMORY ALLOCATION FAILED]\n");
                            exit(1);
                        }
                        temp = first;
                        while(temp != NULL)
                        {
                            fprintf(fp2, "%s\n", temp->Name);
                            fprintf(fp2, "%s\n", temp->Last_name);
                            fprintf(fp2, "%s\n", temp->Postal_code);
                            fprintf(fp2, "%s\n", temp->Username);
                            fprintf(fp2, "%s\n", temp->ID);
                            fprintf(fp2, "%s\n", temp->Mobile_number);
                            fprintf(fp2, "%s\n", temp->Email);
                            fprintf(fp2, "%s\n", temp->Password1);
                            temp = temp->next;
                        }
                        fclose(fp1);
                        fclose(fp2);
                        remove("Profile_user_sign_up.txt");
                        rename("temp.txt", "Profile_user_sign_up.txt");
                        printf("\e[32mChanges saved successfully\e[m");
                        Sleep(2000);
                        system("cls");
                        settings();
                        break;
                    }


                case 7:
                    {
                        printf("Enter your new Password: ");
                        scanf("%s", new_passwordd);
                        getchar();
                        strcpy(temp->Password1, new_passwordd);
                        fp2 = fopen("temp.txt", "w");
                        if (fp2 == NULL)
                        {
                            printf("[MEMORY ALLOCATION FAILED]\n");
                            exit(1);
                        }
                        temp = first;
                        while(temp != NULL)
                        {
                            fprintf(fp2, "%s\n", temp->Name);
                            fprintf(fp2, "%s\n", temp->Last_name);
                            fprintf(fp2, "%s\n", temp->Postal_code);
                            fprintf(fp2, "%s\n", temp->Username);
                            fprintf(fp2, "%s\n", temp->ID);
                            fprintf(fp2, "%s\n", temp->Mobile_number);
                            fprintf(fp2, "%s\n", temp->Email);
                            fprintf(fp2, "%s\n", temp->Password1);
                            temp = temp->next;
                        }
                        fclose(fp1);
                        fclose(fp2);
                        remove("Profile_user_sign_up.txt");
                        rename("temp.txt", "Profile_user_sign_up.txt");
                        printf("\e[32mChanges saved successfully\e[m");
                        Sleep(2000);
                        system("cls");
                        settings();
                        break;
                    }


                case 8:
                    menu2();
                    break;
                default:
                    printf("\e[31mThe entered number is unavailable!\e[m\n");
                    Sleep(2000);
                    printf("Press any key to try again...");
                    getch();
                    system("cls");
                    settings();
                    break;
            }
        }
        temp = temp->next;
    }
}
void Residential_Property_For_Sale(void)
{
    struct Residential_property_information_for_sale *start = NULL;
    struct Residential_property_information_for_sale *last = NULL;
    struct Residential_property_information_for_sale *p1 = malloc(sizeof(struct Residential_property_information_for_sale));
    if (p1 == NULL)
    {
        printf("\e[31m[MEMORY ALLOCATION FAILED]\e[m\n");
        exit(1);
    }

    FILE *fp1;
    fp1 = fopen("Residential_property_information_for_sale.txt", "a");
    if (fp1 == NULL)
    {
        printf("\e[31mERROR: File Residential_property_information_for_sale.txt not found!\e[m");
        exit(1);
    }
    while(1)
    {
        int a = 0;
        printf("Enter the propertyID:");
        fgets(p1->propertyID, sizeof(p1->propertyID), stdin);
        p1->propertyID[strcspn(p1->propertyID, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->propertyID); i++)
        {
            if(isdigit(p1->propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }

    while(1)
    {
        int a = 0;
        printf("Enter the Municipal area:");
        fgets(p1->Municipal_area, sizeof(p1->Municipal_area), stdin);
        p1->Municipal_area[strcspn(p1->Municipal_area, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->Municipal_area); i++)
        {
            if(isdigit(p1->Municipal_area[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Exact address:");
        fgets(p1->Exact_address, sizeof(p1->Exact_address), stdin);
        p1->Exact_address[strcspn(p1->Exact_address, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->Exact_address); i++)
        {
            if(isalpha(p1->Exact_address[i]) == 0 && p1->Exact_address == "_")
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Property Type(apartment or villa):");
        fgets(p1->Property_Type, sizeof(p1->Property_Type), stdin);
        p1->Property_Type[strcspn(p1->Property_Type, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->Property_Type); i++)
        {
            if(isalpha(p1->Property_Type[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
        if(strcmp(p1->Property_Type, "apartment") != 0 && strcmp(p1->Property_Type, "Apartment") != 0 && strcmp(p1->Property_Type, "villa") != 0 && strcmp(p1->Property_Type, "Villa") != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("Input should be apartment or villa\n\n");
            continue;

        }
        break;

    }

    while(1)
    {
        int a = 0;
        printf("Enter the Age of the property:");
        fgets(p1->Age_of_the_property, sizeof(p1->Age_of_the_property), stdin);
        p1->Age_of_the_property[strcspn(p1->Age_of_the_property, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->Age_of_the_property); i++)
        {
            if(isdigit(p1->Age_of_the_property[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Size of the infrastructure:");
        fgets(p1->Size_of_the_infrastructure, sizeof(p1->Size_of_the_infrastructure), stdin);
        p1->Size_of_the_infrastructure[strcspn(p1->Size_of_the_infrastructure, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->Size_of_the_infrastructure); i++)
        {
            if(isdigit(p1->Size_of_the_infrastructure[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Floor:");
        fgets(p1->Floor, sizeof(p1->Floor), stdin);
        p1->Floor[strcspn(p1->Floor, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->Floor); i++)
        {
            if(isdigit(p1->Floor[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Size of the main land:");
        fgets(p1->Size_of_the_main_land, sizeof(p1->Size_of_the_main_land), stdin);
        p1->Size_of_the_main_land[strcspn(p1->Size_of_the_main_land, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->Size_of_the_main_land); i++)
        {
            if(isdigit(p1->Size_of_the_main_land[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


   while(1)
    {
        int a = 0;
        printf("Enter Phone number of the owner:");
        fgets(p1->number_of_the_owner, sizeof(p1->number_of_the_owner), stdin);
        p1->number_of_the_owner[strcspn(p1->number_of_the_owner, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->number_of_the_owner); i++)
        {
            if(isdigit(p1->number_of_the_owner[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                if (strncmp(p1->number_of_the_owner, "09", 2) != 0)
        {
            a++;
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("The entered format is not correct\n\n");
            continue;
        }

        if(strlen(p1->number_of_the_owner) != 11)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter \e[4m11\e[m Number\n\n");
            continue;
        }
        break;

    }


   while(1)
    {
        int a = 0;
        printf("Enter the Number of bedrooms:");
        fgets(p1->Number_of_bedrooms, sizeof(p1->Number_of_bedrooms), stdin);
        p1->Number_of_bedrooms[strcspn(p1->Number_of_bedrooms, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->Number_of_bedrooms); i++)
        {
            if(isdigit(p1->Number_of_bedrooms[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Price:");
        fgets(p1->Price, sizeof(p1->Price), stdin);
        p1->Price[strcspn(p1->Price, "\n")] = '\0';
        for (int i = 0; i < strlen(p1->Price); i++)
        {
            if(isdigit(p1->Price[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }
    printf("\n");
    p1->isActive = 1;
    printf("\e[32mYour information has been successfully registered...\e[m\n");
    fprintf(fp1, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n", p1->propertyID, p1->Municipal_area, p1->Exact_address, p1->Property_Type, p1->Age_of_the_property,
            p1->Size_of_the_infrastructure, p1->Floor, p1->Size_of_the_main_land, p1->number_of_the_owner, p1->Number_of_bedrooms, p1->Price, p1->isActive);
    fclose(fp1);

    printf("Press any key for back to the menu...\n");
    getch();
    system("cls");
    if (start == NULL)
    {
        start = p1;
        start->next = NULL;
        last = start;
    }
    else
    {
        last->next = p1;
        last = p1;
        last->next = NULL;
    }
    menu2();
}

void Office_property_for_sale(void)
{
    struct Office_property_information_for_sale *start = NULL;
    struct Office_property_information_for_sale *last = NULL;
    struct Office_property_information_for_sale *q1 = malloc(sizeof(struct Office_property_information_for_sale));
    FILE *fp2;
    fp2 = fopen("Office_property_information_for_sale.txt","a");
    if(fp2 == NULL)
    {
        printf("\e[31mERROR: File Office_property_information_for_sale.txt not found!\e[m");
        exit(1);
    }
    if(q1 ==  NULL)
    {
        printf("\e[31m[MEMORY ALLOCATION FAILED]\e[m\n");
        exit(1);
    }

    while(1)
    {
        int a = 0;
        printf("Enter the propertyID:");
        fgets(q1->propertyID, sizeof(q1->propertyID), stdin);
        q1->propertyID[strcspn(q1->propertyID, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->propertyID); i++)
        {
            if(isdigit(q1->propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }

    while(1)
    {
        int a = 0;
        printf("Enter the Municipal area:");
        fgets(q1->Municipal_area, sizeof(q1->Municipal_area), stdin);
        q1->Municipal_area[strcspn(q1->Municipal_area, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->Municipal_area); i++)
        {
            if(isdigit(q1->Municipal_area[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Exact address:");
        fgets(q1->Exact_address, sizeof(q1->Exact_address), stdin);
        q1->Exact_address[strcspn(q1->Exact_address, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->Exact_address); i++)
        {
            if(isalpha(q1->Exact_address[i]) == 0 && q1->Exact_address == "_")
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Property Type(apartment or villa):");
        fgets(q1->Property_Type, sizeof(q1->Property_Type), stdin);
        q1->Property_Type[strcspn(q1->Property_Type, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->Property_Type); i++)
        {
            if(isalpha(q1->Property_Type[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
        if(strcmp(q1->Property_Type, "apartment") != 0 && strcmp(q1->Property_Type, "Apartment") != 0 && strcmp(q1->Property_Type, "villa") != 0 && strcmp(q1->Property_Type, "Villa") != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("Input should be apartment or villa\n\n");
            continue;

        }
        break;

    }

    while(1)
    {
        int a = 0;
        printf("Enter the Age of the property:");
        fgets(q1->Age_of_the_property, sizeof(q1->Age_of_the_property), stdin);
        q1->Age_of_the_property[strcspn(q1->Age_of_the_property, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->Age_of_the_property); i++)
        {
            if(isdigit(q1->Age_of_the_property[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Size of the infrastructure:");
        fgets(q1->Size_of_the_infrastructure, sizeof(q1->Size_of_the_infrastructure), stdin);
        q1->Size_of_the_infrastructure[strcspn(q1->Size_of_the_infrastructure, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->Size_of_the_infrastructure); i++)
        {
            if(isdigit(q1->Size_of_the_infrastructure[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Floor:");
        fgets(q1->Floor, sizeof(q1->Floor), stdin);
        q1->Floor[strcspn(q1->Floor, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->Floor); i++)
        {
            if(isdigit(q1->Floor[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Size of the main land:");
        fgets(q1->Size_of_the_main_land, sizeof(q1->Size_of_the_main_land), stdin);
        q1->Size_of_the_main_land[strcspn(q1->Size_of_the_main_land, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->Size_of_the_main_land); i++)
        {
            if(isdigit(q1->Size_of_the_main_land[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


   while(1)
    {
        int a = 0;
        printf("Enter Phone number of the owner:");
        fgets(q1->number_of_the_owner, sizeof(q1->number_of_the_owner), stdin);
        q1->number_of_the_owner[strcspn(q1->number_of_the_owner, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->number_of_the_owner); i++)
        {
            if(isdigit(q1->number_of_the_owner[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                if (strncmp(q1->number_of_the_owner, "09", 2) != 0)
        {
            a++;
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("The entered format is not correct\n\n");
            continue;
        }

        if(strlen(q1->number_of_the_owner) != 11)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter \e[4m11\e[m Number\n\n");
            continue;
        }
        break;

    }


   while(1)
    {
        int a = 0;
        printf("Enter the Number of bedrooms:");
        fgets(q1->Number_of_office_rooms, sizeof(q1->Number_of_office_rooms), stdin);
        q1->Number_of_office_rooms[strcspn(q1->Number_of_office_rooms, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->Number_of_office_rooms); i++)
        {
            if(isdigit(q1->Number_of_office_rooms[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                break;

    }


    while(1)
    {
        int a = 0;
        printf("Enter the Price:");
        fgets(q1->Price, sizeof(q1->Price), stdin);
        q1->Price[strcspn(q1->Price, "\n")] = '\0';
        for (int i = 0; i < strlen(q1->Price); i++)
        {
            if(isdigit(q1->Price[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    printf("\n");
    q1->isActive = 1;
    printf("\e[32mYour information has been successfully registered...\e[m\n");
    fprintf(fp2, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n", q1->propertyID, q1->Municipal_area, q1->Exact_address, q1->Property_Type, q1->Age_of_the_property,
             q1->Size_of_the_infrastructure, q1->Floor, q1->Size_of_the_main_land, q1->number_of_the_owner, q1->Number_of_office_rooms, q1->Price, q1->isActive);
    fclose(fp2);

    printf("Press any key for back to the menu...\n");
    getch();
    system("cls");

    if(start == NULL)
    {
        start = q1;
        start->next = NULL;
        last = start;
    }
    else
    {
        last->next = q1;
        last = q1;
        last->next = NULL;
    }
    menu2();
}

void Land_sales(void)
{
    struct Land_sales_information *start = NULL;
    struct Land_sales_information *last = NULL;
    struct Land_sales_information *q2 = malloc(sizeof(struct Land_sales_information));
    if(q2 ==  NULL)
    {
        printf("\e[31m[MEMORY ALLOCATION FAILED]\e[m\n");
        exit(1);
    }
    FILE *fp3;
    fp3 = fopen("Land_sales_information.txt","a");
    if(fp3 == NULL)
    {
        printf("\e[31mERROR: File Land_sales_information.txt not found!\e[m");
        exit(1);
    }
    while(1)
    {
        int a = 0;
        printf("Enter the propertyID:");
        fgets(q2->propertyID, sizeof(q2->propertyID), stdin);
        q2->propertyID[strcspn(q2->propertyID, "\n")] = '\0';
        for (int i = 0; i < strlen(q2->propertyID); i++)
        {
            if(isdigit(q2->propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }



    while(1)
    {
        int a = 0;
        printf("Enter the Municipal area:");
        fgets(q2->Municipal_area, sizeof(q2->Municipal_area), stdin);
        q2->Municipal_area[strcspn(q2->Municipal_area, "\n")] = '\0';
        for (int i = 0; i < strlen(q2->Municipal_area); i++)
        {
            if(isdigit(q2->Municipal_area[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
        printf("Enter the Exact address:");
        fgets(q2->Exact_address, sizeof(q2->Exact_address), stdin);
        q2->Exact_address[strcspn(q2->Exact_address, "\n")] = '\0';
        for (int i = 0; i < strlen(q2->Exact_address); i++)
        {
            if(isalpha(q2->Exact_address[i]) == 0 && q2->Exact_address == "_")
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
        printf("Enter the land Type(Agricultural or urban):");//شهری
        fgets(q2->land_Type, sizeof(q2->land_Type), stdin);
        q2->land_Type[strcspn(q2->land_Type, "\n")] = '\0';
        for (int i = 0; i < strlen(q2->land_Type); i++)
        {
            if(isalpha(q2->land_Type[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
            if(strcmp(q2->land_Type, "Agricultural") != 0 && strcmp(q2->land_Type, "agricultural") != 0 && strcmp(q2->land_Type, "urban") != 0 && strcmp(q2->land_Type, "Urban") != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("Input should be agricultural or urban\n\n");
            continue;

        }
        break;
    }


    while(1)
    {
        int a = 0;
        printf("Enter the Size of the land:");
        fgets(q2->Size_of_the_land, sizeof(q2->Size_of_the_land), stdin);
        q2->Size_of_the_land[strcspn(q2->Size_of_the_land, "\n")] = '\0';
        for (int i = 0; i < strlen(q2->Size_of_the_land); i++)
        {
            if(isdigit(q2->Size_of_the_land[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter Phone number of the owner:");
    fgets(q2->number_of_the_owner, sizeof(q2->number_of_the_owner), stdin);
    q2->number_of_the_owner[strcspn(q2->number_of_the_owner, "\n")] = '\0';
        for (int i = 0; i < strlen(q2->number_of_the_owner); i++)
        {
            if(isdigit(q2->number_of_the_owner[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                if (strncmp(q2->number_of_the_owner, "09", 2) != 0)
        {
            a++;
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("The entered format is not correct\n\n");
            continue;
        }

        if(strlen(q2->number_of_the_owner) != 11)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter \e[4m11\e[m Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Price:");
    fgets(q2->Price, sizeof(q2->Price), stdin);
    q2->Price[strcspn(q2->Price, "\n")] = '\0';
        for (int i = 0; i < strlen(q2->Price); i++)
        {
            if(isdigit(q2->Price[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    printf("\n");
    q2->isActive = 1;
    printf("\e[32mYour information has been successfully registered...\e[m\n");
    fprintf(fp3, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n", q2->propertyID, q2->Municipal_area, q2->Exact_address, q2->land_Type, q2->Size_of_the_land,
             q2->number_of_the_owner, q2->Price, q2->isActive);
    fclose(fp3);

    printf("Press any key for back to the menu...\n");
    getch();
    system("cls");
    if(start == NULL)
    {
        start = q2;
        start->next = NULL;
        last = start;
    }
    else
    {
        last->next = q2;
        last = q2;
        last->next = NULL;
    }
    menu2();
}

void Residential_property_for_rent(void)
{
    struct Residential_property_information_for_rent *start = NULL;
    struct Residential_property_information_for_rent *last = NULL;
    struct Residential_property_information_for_rent *q3 = malloc(sizeof(struct Residential_property_information_for_rent));
    if(q3 ==  NULL)
    {
        printf("\e[31m[MEMORY ALLOCATION FAILED]\e[m\n");
        exit(1);
    }
    FILE *fp4;
    fp4 = fopen("Residential_property_information_for_rent.txt","a");
    if(fp4 == NULL)
    {
        printf("\e[31mERROR: File Residential_property_information_for_rent.txt not found!\e[m");
        exit(1);
    }
    while(1)
    {
        int a = 0;
        printf("Enter the propertyID: ");
        fgets(q3->propertyID, sizeof(q3->propertyID), stdin);
        q3->propertyID[strcspn(q3->propertyID, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->propertyID); i++)
        {
            if(isdigit(q3->propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }



    while(1)
    {
        int a = 0;
    printf("Enter the Municipal area: ");
    fgets(q3->Municipal_area, sizeof(q3->Municipal_area), stdin);
    q3->Municipal_area[strcspn(q3->Municipal_area, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->Municipal_area); i++)
        {
            if(isdigit(q3->Municipal_area[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Exact address: ");
    fgets(q3->Exact_address, sizeof(q3->Exact_address), stdin);
    q3->Exact_address[strcspn(q3->Exact_address, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->Exact_address); i++)
        {
            if(isalpha(q3->Exact_address[i]) == 0 && q3->Exact_address == "_")
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Property Type(apartment or villa): ");
    fgets(q3->Property_Type, sizeof(q3->Property_Type), stdin);
    q3->Property_Type[strcspn(q3->Property_Type, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->Property_Type); i++)
        {
            if(isalpha(q3->Property_Type[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
        if(strcmp(q3->Property_Type, "apartment") != 0 && strcmp(q3->Property_Type, "Apartment") != 0 && strcmp(q3->Property_Type, "villa") != 0 && strcmp(q3->Property_Type, "Villa") != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("Input should be apartment or villa\n\n");
            continue;

        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Age of the property: ");
    fgets(q3->Age_of_the_property, sizeof(q3->Age_of_the_property), stdin);
    q3->Age_of_the_property[strcspn(q3->Age_of_the_property, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->Age_of_the_property); i++)
        {
            if(isdigit(q3->Age_of_the_property[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Size of the infrastructure:");
    fgets(q3->Size_of_the_infrastructure, sizeof(q3->Size_of_the_infrastructure), stdin);
    q3->Size_of_the_infrastructure[strcspn(q3->Size_of_the_infrastructure, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->Size_of_the_infrastructure); i++)
        {
            if(isdigit(q3->Size_of_the_infrastructure[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Floor:");
    fgets(q3->Floor, sizeof(q3->Floor), stdin);
    q3->Floor[strcspn(q3->Floor, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->Floor); i++)
        {
            if(isdigit(q3->Floor[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Size of the main land:");
    fgets(q3->Size_of_the_main_land, sizeof(q3->Size_of_the_main_land), stdin);
    q3->Size_of_the_main_land[strcspn(q3->Size_of_the_main_land, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->Size_of_the_main_land); i++)
        {
            if(isdigit(q3->Size_of_the_main_land[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter Phone number of the owner:");
    fgets(q3->number_of_the_owner, sizeof(q3->number_of_the_owner), stdin);
    q3->number_of_the_owner[strcspn(q3->number_of_the_owner, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->number_of_the_owner); i++)
        {
            if(isdigit(q3->number_of_the_owner[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                if (strncmp(q3->number_of_the_owner, "09", 2) != 0)
        {
            a++;
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("The entered format is not correct\n\n");
            continue;
        }

        if(strlen(q3->number_of_the_owner) != 11)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter \e[4m11\e[m Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Number of bedrooms:");
    fgets(q3->Number_of_bedrooms, sizeof(q3->Number_of_bedrooms), stdin);
    q3->Number_of_bedrooms[strcspn(q3->Number_of_bedrooms, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->Number_of_bedrooms); i++)
        {
            if(isdigit(q3->Number_of_bedrooms[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the mortgage:");
    fgets(q3->mortgage, sizeof(q3->mortgage), stdin);
    q3->mortgage[strcspn(q3->mortgage, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->mortgage); i++)
        {
            if(isdigit(q3->mortgage[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
        printf("Enter the Rent:");
        fgets(q3->Rent, sizeof(q3->Rent), stdin);
        q3->Rent[strcspn(q3->Rent, "\n")] = '\0';
        for (int i = 0; i < strlen(q3->Rent); i++)
        {
            if(isdigit(q3->Rent[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    printf("\n");
    q3->isActive = 1;
    printf("\e[32mYour information has been successfully registered...\e[m\n");
    fprintf(fp4, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n", q3->propertyID, q3->Municipal_area, q3->Exact_address, q3->Property_Type, q3->Age_of_the_property,
             q3->Size_of_the_infrastructure, q3->Floor, q3->Size_of_the_main_land, q3->number_of_the_owner, q3->Number_of_bedrooms, q3->mortgage, q3->Rent, q3->isActive);
    fclose(fp4);

    printf("Press any key for back to the menu...\n");
    getch();
    system("cls");
    if(start == NULL)
    {
        start = q3;
        start->next = NULL;
        last = start;
    }
    else
    {
        last->next = q3;
        last = q3;
        last->next = NULL;
    }
    menu2();
}

void Office_property_for_rent(void)
{
    struct Office_property_information_for_rent *start = NULL;
    struct Office_property_information_for_rent *last = NULL;
    struct Office_property_information_for_rent *q4 = malloc(sizeof(struct Office_property_information_for_rent));
    if(q4 ==  NULL)
    {
        printf("\e[31m[MEMORY ALLOCATION FAILED]\e[m\n");
        exit(1);
    }
    FILE *fp5;
    fp5 = fopen("Office_property_information_for_rent.txt","a");
    if(fp5 == NULL)
    {
        printf("\e[31mERROR: File Office_property_information_for_rent.txt not found!\e[m");
        exit(1);
    }
    while(1)
    {
        int a = 0;
        printf("Enter the propertyID:");
        fgets(q4->propertyID, sizeof(q4->propertyID), stdin);
        q4->propertyID[strcspn(q4->propertyID, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->propertyID); i++)
        {
            if(isdigit(q4->propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }



    while(1)
    {
        int a = 0;
    printf("Enter the Municipal area:");
    fgets(q4->Municipal_area, sizeof(q4->Municipal_area), stdin);
    q4->Municipal_area[strcspn(q4->Municipal_area, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->Municipal_area); i++)
        {
            if(isdigit(q4->Municipal_area[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Exact address:");
    fgets(q4->Exact_address, sizeof(q4->Exact_address), stdin);
    q4->Exact_address[strcspn(q4->Exact_address, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->Exact_address); i++)
        {
            if(isalpha(q4->Exact_address[i]) == 0 && q4->Exact_address == "_")
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Property Type(apartment or villa):");
    fgets(q4->Property_Type, sizeof(q4->Property_Type), stdin);
    q4->Property_Type[strcspn(q4->Property_Type, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->Property_Type); i++)
        {
            if(isalpha(q4->Property_Type[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
        if(strcmp(q4->Property_Type, "apartment") != 0 && strcmp(q4->Property_Type, "Apartment") != 0 && strcmp(q4->Property_Type, "villa") != 0 && strcmp(q4->Property_Type, "Villa") != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("Input should be apartment or villa\n\n");
            continue;

        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Age of the property:");
    fgets(q4->Age_of_the_property, sizeof(q4->Age_of_the_property), stdin);
    q4->Age_of_the_property[strcspn(q4->Age_of_the_property, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->Age_of_the_property); i++)
        {
            if(isdigit(q4->Age_of_the_property[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
     printf("Enter the Size of the infrastructure:");
    fgets(q4->Size_of_the_infrastructure, sizeof(q4->Size_of_the_infrastructure), stdin);
    q4->Size_of_the_infrastructure[strcspn(q4->Size_of_the_infrastructure, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->Size_of_the_infrastructure); i++)
        {
            if(isdigit(q4->Size_of_the_infrastructure[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    while(1)
    {
        int a = 0;
    printf("Enter the Floor:");
    fgets(q4->Floor, sizeof(q4->Floor), stdin);
    q4->Floor[strcspn(q4->Floor, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->Floor); i++)
        {
            if(isdigit(q4->Floor[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Size of the main land:");
    fgets(q4->Size_of_the_main_land, sizeof(q4->Size_of_the_main_land), stdin);
    q4->Size_of_the_main_land[strcspn(q4->Size_of_the_main_land, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->Size_of_the_main_land); i++)
        {
            if(isdigit(q4->Size_of_the_main_land[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter Phone number of the owner:");
    fgets(q4->number_of_the_owner, sizeof(q4->number_of_the_owner), stdin);
    q4->number_of_the_owner[strcspn(q4->number_of_the_owner, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->number_of_the_owner); i++)
        {
            if(isdigit(q4->number_of_the_owner[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
                if (strncmp(q4->number_of_the_owner, "09", 2) != 0)
        {
            a++;
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("The entered format is not correct\n\n");
            continue;
        }

        if(strlen(q4->number_of_the_owner) != 11)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter \e[4m11\e[m Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Number of bedrooms:");
    fgets(q4->Number_of_office_rooms, sizeof(q4->Number_of_office_rooms), stdin);
    q4->Number_of_office_rooms[strcspn(q4->Number_of_office_rooms, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->Number_of_office_rooms); i++)
        {
            if(isdigit(q4->Number_of_office_rooms[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the mortgage:");
    fgets(q4->mortgage, sizeof(q4->mortgage), stdin);
    q4->mortgage[strcspn(q4->mortgage, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->mortgage); i++)
        {
            if(isdigit(q4->mortgage[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Rent:");
    fgets(q4->Rent, sizeof(q4->Rent), stdin);
    q4->Rent[strcspn(q4->Rent, "\n")] = '\0';
        for (int i = 0; i < strlen(q4->Rent); i++)
        {
            if(isdigit(q4->Rent[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }

    printf("\n");
    q4->isActive = 1;
    printf("\e[32mYour information has been successfully registered...\e[m\n");
    fprintf(fp5, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n", q4->propertyID, q4->Municipal_area, q4->Exact_address, q4->Property_Type, q4->Age_of_the_property,
             q4->Size_of_the_infrastructure, q4->Floor, q4->Size_of_the_main_land, q4->number_of_the_owner, q4->Number_of_office_rooms, q4->mortgage, q4->Rent, q4->isActive);
    fclose(fp5);

    printf("Press any key for back to the menu...\n");
    getch();
    system("cls");
    if(start == NULL)
    {
        start = q4;
        start->next = NULL;
        last = start;
    }
    else
    {
        last->next = q4;
        last = q4;
        last->next = NULL;
    }
    menu2();

}

void Land_rent(void)
{
    struct Land_rent_information *start = NULL;
    struct Land_rent_information *last = NULL;
    struct Land_rent_information *q5 = malloc(sizeof(struct Land_rent_information));
    if (q5 == NULL)
    {
        printf("\e[31m[MEMORY ALLOCATION FAILED]\e[m\n");
        exit(1);
    }
    FILE *fp6;
    fp6 = fopen("Land_rent_information.txt", "a");
    if (fp6 == NULL) {
        printf("\e[31mERROR: File Land_rent_information.txt not found!\e[m");
        exit(1);
    }

    while(1)
    {
        int a = 0;
    printf("Enter the propertyID:");
    fgets(q5->propertyID, sizeof(q5->propertyID), stdin);
    q5->propertyID[strcspn(q5->propertyID, "\n")] = '\0';
        for (int i = 0; i < strlen(q5->propertyID); i++)
        {
            if(isdigit(q5->propertyID[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }



    while(1)
    {
        int a = 0;
    printf("Enter the Municipal area:");
    fgets(q5->Municipal_area, sizeof(q5->Municipal_area), stdin);
    q5->Municipal_area[strcspn(q5->Municipal_area, "\n")] = '\0';
        for (int i = 0; i < strlen(q5->Municipal_area); i++)
        {
            if(isdigit(q5->Municipal_area[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Exact address:");
    fgets(q5->Exact_address, sizeof(q5->Exact_address), stdin);
    q5->Exact_address[strcspn(q5->Exact_address, "\n")] = '\0';
        for (int i = 0; i < strlen(q5->Exact_address); i++)
        {
            if(isalpha(q5->Exact_address[i]) == 0 && q5->Exact_address == "_")
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Property Type(Agricultural or urban):");
    fgets(q5->land_Type, sizeof(q5->land_Type), stdin);
    q5->land_Type[strcspn(q5->land_Type, "\n")] = '\0';
        for (int i = 0; i < strlen(q5->land_Type); i++)
        {
            if(isalpha(q5->land_Type[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter word\n\n");
            continue;
        }
        if(strcmp(q5->land_Type, "Agricultural") != 0 && strcmp(q5->land_Type, "agricultural") != 0 && strcmp(q5->land_Type, "urban") != 0 && strcmp(q5->land_Type, "Urban") != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("Input should be agricultural or urban\n\n");
            continue;

        }
        break;
    }

    while(1)
    {
        int a = 0;
    printf("Enter the Size of the land:");
    fgets(q5->Size_of_the_land, sizeof(q5->Size_of_the_land), stdin);
    q5->Size_of_the_land[strcspn(q5->Size_of_the_land, "\n")] = '\0';
        for (int i = 0; i < strlen(q5->Size_of_the_land); i++)
        {
            if(isdigit(q5->Size_of_the_land[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter Phone number of the owner:");
    fgets(q5->number_of_the_owner, sizeof(q5->number_of_the_owner), stdin);
    q5->number_of_the_owner[strcspn(q5->number_of_the_owner, "\n")] = '\0';
        for (int i = 0; i < strlen(q5->number_of_the_owner); i++)
        {
            if(isdigit(q5->number_of_the_owner[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        if (strncmp(q5->number_of_the_owner, "09", 2) != 0)
        {
            a++;
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("The entered format is not correct\n\n");
            continue;
        }

        if(strlen(q5->number_of_the_owner) != 11)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter \e[4m11\e[m Number\n\n");
            continue;
        }

        break;
    }

    while(1)
    {
        int a = 0;
    printf("Enter the mortgage:");
    fgets(q5->mortgage, sizeof(q5->mortgage), stdin);
    q5->mortgage[strcspn(q5->mortgage, "\n")] = '\0';
        for (int i = 0; i < strlen(q5->mortgage); i++)
        {
            if(isdigit(q5->mortgage[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }


    while(1)
    {
        int a = 0;
    printf("Enter the Rent:");
    fgets(q5->Rent, sizeof(q5->Rent), stdin);
    q5->Rent[strcspn(q5->Rent, "\n")] = '\0';
        for (int i = 0; i < strlen(q5->Rent); i++)
        {
            if(isdigit(q5->Rent[i]) == 0)
            {
                a++;
            }
        }

        if (a != 0)
        {
            printf("\e[31mTHE INPUT IS NOT CORRECT!\e[m\n");
            printf("You must enter Number\n\n");
            continue;
        }
        break;
    }
    printf("\n");
    q5->isActive = 1;
    printf("\e[32mYour information has been successfully registered...\e[m\n");
    fprintf(fp6, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n", q5->propertyID, q5->Municipal_area, q5->Exact_address, q5->land_Type, q5->Size_of_the_land,
             q5->number_of_the_owner, q5->mortgage, q5->Rent, q5->isActive);
    fclose(fp6);
    printf("Press any key for back to the menu...\n");
    getch();
    system("cls");
    if (start == NULL)
    {
        start = q5;
        start->next = NULL;
        last = start;
    }
    else
    {
        last->next = q5;
        last = q5;
        last->next = NULL;
    }
    menu2();
}





