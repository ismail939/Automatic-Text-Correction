#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node{
    char line[200];
    struct node *next;
};
typedef struct node line_start; // this is the array of char of the line until the '\n'
line_start *head=NULL;

line_start *search(char *name)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        line_start *cur=head;
        while(cur->next){
            printf("%s--%s", name, cur->line);
            int i=0;
            bool check=true;
            while(name[i]!=0)
            {

                if(name[i]!=cur->line[i])
                {
                    check=false;
                }
                i++;
            }
            if(check)
            {
                return cur;
            }
            cur=cur->next->next;
        }
        return NULL;
    }
}

// a function to check grammar
void correctGrammar()
{
    line_start *cur=head;
    while(cur) {
        int i=0;
        while(cur->line[i]) {
            if(cur->line[i]=='\n')
            {
                cur->line[i]=0;
            }
            // first we should deal with the Capitals [ at first of line, after a ',', after a '.', after a ";", after "!"]
            // for the first char in a line
            if(cur->line[0]>='a'&&cur->line[0]<='z')
            {
                cur->line[0]-=32;
            }
            // after any of these [!-.-,-;]
            if(cur->line[i]=='!'||cur->line[i]==';'||cur->line[i]==','||cur->line[i]=='.')
            {
                if(cur->line[i+1]==' ')
                {
                    if(cur->line[i+2]>='a'&&cur->line[i+2]<='z')
                    {
                        cur->line[i+2]-=32;
                    }
                }
                else
                {
                    // before shifting to make a space we check the letter that supposed to be after that space
                    if(cur->line[i+1]>='a'&&cur->line[i+1]<='z')
                    {
                        cur->line[i+1]-=32;
                    }
                    // now we shift the array :(
                    // we wannaa put a space after the dot.
                    char temp1, temp2;
                    temp1 = cur->line[i + 1];
                    temp2 = cur->line[i + 2];
                    cur->line[i + 1] = ' ';
                    for (int j = i + 2; cur->line[j - 1]; j++) {
                        cur->line[j] = temp1;
                        temp1 = temp2;
                        temp2 = cur->line[j + 1];
                    }


                }
            }

            // never two spaces after each other-->done
            if(cur->line[i]==' '&&cur->line[i+1]==' ') // shift back 1
            {
                for(int j=i+1;cur->line[j];j++)
                {
                    cur->line[j]=cur->line[j+1];
                }
            }
            // a bracket that is opened must be closed after exactly on word

            char temp1, temp2;
                label:if(cur->line[i]=='(')
            {
                int y=i+1;
                while(cur->line[y]){
                    if(cur->line[y] > 'z' || cur->line[y] < 'A' || (cur->line[y] > 'Z' && cur->line[y] < 'a'))
                    {
                        if(cur->line[y]!=')')
                        {
                            temp1=cur->line[y];
                            temp2=cur->line[y+1];
                            cur->line[y]=')';
                            for(int j=y+1;1;j++) {

                                cur->line[j] = temp1;
                                temp1 = temp2;
                                temp2 = cur->line[j + 1];
                                if((temp1==0&&temp2==0)||(temp1=='\n'&&temp2=='\n')||(temp1=='\n'&&temp2==0)||(temp1==0&&temp2=='\n')){
                                    i=y+2;
                                    goto label;;
                                }
                            }

                        }
                    }
                    y++;

                }

            }
            else if(cur->line[i]==')')
            {
                int y=i-1;
                while(1)
                {
                    if(cur->line[y] > 'z' || cur->line[y] < 'A' || (cur->line[y] > 'Z' && cur->line[y] < 'a'))
                    {
                        if(cur->line[y]!='(')
                        {
                            temp1='(';
                            temp2=cur->line[y+1];

                            for(int j=y+1;1;j++) {

                                cur->line[j] = temp1;
                                temp1 = temp2;
                                temp2 = cur->line[j + 1];
                                if((temp1==0&&temp2==0)||(temp1=='\n'&&temp2=='\n')||(temp1=='\n'&&temp2==0)||(temp1==0&&temp2=='\n')){
                                    i+=2;
                                    goto label;
                                }
                            }
                        }
                        else if(cur->line[y]=='(')
                        {
                            break;
                        }
                    }
                    y--;
                }
            }
            i++;
            }

        cur=cur->next;

    }
}


void correctOnePersonGrammar(char*name)
{
    if(search(name)==NULL)
    {
        printf("Not even here!!\n");
    }
    line_start *cur= search(name);
    for(int cnt=0;cnt<2;cnt++) {
        int i = 0;
        while (cur->line[i]) {
            if(cur->line[i]=='\n')
            {
                cur->line[i]=0;
            }
            // first we should deal with the Capitals [ at first of line, after a ',', after a '.', after a ";", after "!"]
            // for the first char in a line
            if(cur->line[0]>='a'&&cur->line[0]<='z')
            {
                cur->line[0]-=32;
            }
            // after any of these [!-.-,-;]
            if(cur->line[i]=='!'||cur->line[i]==';'||cur->line[i]==','||cur->line[i]=='.')
            {
                if(cur->line[i+1]==' ')
                {
                    if(cur->line[i+2]>='a'&&cur->line[i+2]<='z')
                    {
                        cur->line[i+2]-=32;
                    }
                }
                else
                {
                    // before shifting to make a space we check the letter that supposed to be after that space
                    if(cur->line[i+1]>='a'&&cur->line[i+1]<='z')
                    {
                        cur->line[i+1]-=32;
                    }
                    // now we shift the array :(
                    // we wannaa put a space after the dot.
                    char temp1, temp2;
                    temp1 = cur->line[i + 1];
                    temp2 = cur->line[i + 2];
                    cur->line[i + 1] = ' ';
                    for (int j = i + 2; cur->line[j - 1]; j++) {
                        cur->line[j] = temp1;
                        temp1 = temp2;
                        temp2 = cur->line[j + 1];
                    }


                }
            }

            // never two spaces after each other-->done
            if(cur->line[i]==' '&&cur->line[i+1]==' ') // shift back 1
            {
                for(int j=i+1;cur->line[j];j++)
                {
                    cur->line[j]=cur->line[j+1];
                }
            }
            // a bracket that is opened must be closed after exactly on word



            char temp1, temp2;
            label:if(cur->line[i]=='(')
        {
            int y=i+1;
            while(cur->line[y]){
                if(cur->line[y] > 'z' || cur->line[y] < 'A' || (cur->line[y] > 'Z' && cur->line[y] < 'a'))
                {
                    if(cur->line[y]!=')')
                    {
                        temp1=cur->line[y];
                        temp2=cur->line[y+1];
                        cur->line[y]=')';
                        for(int j=y+1;1;j++) {

                            cur->line[j] = temp1;
                            temp1 = temp2;
                            temp2 = cur->line[j + 1];
                            if((temp1==0&&temp2==0)||(temp1=='\n'&&temp2=='\n')||(temp1=='\n'&&temp2==0)||(temp1==0&&temp2=='\n')){
                                i=y+2;
                                goto label;;
                            }
                        }

                    }
                }
                y++;

            }

        }
        else if(cur->line[i]==')')
        {
            int y=i-1;
            while(1)
            {
                if(cur->line[y] > 'z' || cur->line[y] < 'A' || (cur->line[y] > 'Z' && cur->line[y] < 'a'))
                {
                    if(cur->line[y]!='(')
                    {
                        temp1='(';
                        temp2=cur->line[y+1];

                        for(int j=y+1;1;j++) {

                            cur->line[j] = temp1;
                            temp1 = temp2;
                            temp2 = cur->line[j + 1];
                            if((temp1==0&&temp2==0)||(temp1=='\n'&&temp2=='\n')||(temp1=='\n'&&temp2==0)||(temp1==0&&temp2=='\n')){
                                i+=2;
                                goto label;
                            }
                        }
                    }
                    else if(cur->line[y]=='(')
                    {
                        break;
                    }
                }
                y--;
            }
        }
            i++;
        }
        cur = cur->next;
    }
}

/*void add_Space(char *garfield, int i) {
    //char garfield[20]="h.rsv";
    // we wannaa put a space after the dot.
    char temp1, temp2;

    if (garfield[i] == '.' || garfield[i] == ';' || garfield[i] == ',' || garfield[i] == '!') {
        temp1 = garfield[i + 1];
        temp2 = garfield[i + 2];
        garfield[i + 1] = ' ';
        for (int j = i + 2; garfield[j - 1]; j++) {
            garfield[j] = temp1;
            temp1 = temp2;
            temp2 = garfield[j + 1];
        }
    }
}
*/

// lets make a function to insert a node(line start)
void insertLine(char *newLine) {
    line_start *newLineStart = (line_start *) malloc(sizeof(line_start)); // dynamically allocating a new line start node

    strcpy(newLineStart->line, newLine); // initializing the data of the node

    if (head == NULL) {
        head = newLineStart;
        head->next = NULL;
    } else {
        line_start *cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = newLineStart; // adding a new line node to the linked lines list
        cur->next->next = NULL;
    }

}
// lets make a function to print the whole file(linked list of lines)
    void printFile(FILE *fp) {
        if (head == NULL) {
            return;
        }
        line_start *cur = head;
        while (cur) {
            int i = 0;
            while (cur->line[i] != '\n') {
                if (cur->line[i - 1] == '.' && (cur->line[i] > 'z' || cur->line[i] < 'A' ||
                                                (cur->line[i] > 'Z' && cur->line[i] < 'a'))) // problem not here
                    break;
                printf("%c", cur->line[i]);
                i++;
            }
            printf("\n");
            cur = cur->next;
        }
    }

    void printInFile(FILE *fp) {
        fp = fopen("Output.txt", "w");
        line_start *cur = head;
        while (cur) {
            fputs(cur->line, fp);
            fputs("\n", fp);
            cur = cur->next;
        }
        fclose(fp);
    }
int main() {


        FILE *fp = NULL;
        FILE *fp2 = NULL;
        fp = fopen("Input.txt", "r");
        if (fp == NULL) {
            printf("File doesn't exist!\n");
            return 0;
        }
        char str[80];
        while (!feof(fp)) {
            fgets(str, 100, fp);
            if (str[0] > 'z' || str[0] < 'A' || (str[0] > 'Z' && str[0] < 'a')) // problem not here
                break;
            insertLine(str);
        }
        printFile(fp);

        if (search("Mahmoud Hussain")) {
            printf("Found");
        } else
            printf("Not Found");
        correctGrammar();
        printInFile(fp2);
        fclose(fp);
    }




