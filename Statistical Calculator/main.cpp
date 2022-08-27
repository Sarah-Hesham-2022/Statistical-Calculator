#include <iostream>

using namespace std;
void general(int[],int,int);
int mode(int[],int);
float median(int[],int);
float mean(int[],int);
void sorting(int[],int,bool);
int range(int[],int);
void frequency(int[],int);
void shift(int[],int,int);
int main()
{
    cout<<"enter the size of the array"<<endl;
    int content,choice;
    cin>>content;
    cout<<"enter the elements of the array but,only positive values"<<endl;
    int *myarray;
    myarray=new int [content];
    for(int i=0;i<content;i++)
        cin>>myarray[i];
   cout<<"now choose one of the following "<<endl;
   cout<<"1-Mode"<<endl;
   cout<<"2-Median"<<endl;
   cout<<"3-Mean"<<endl;
   cout<<"4-sort"<<endl;
   cout<<"5-Range"<<endl;
   cout<<"6-Element frequency"<<endl;
   cout<<"7-Element circular shifter"<<endl;
   cout<<"8-Exit"<<endl;
   cout<<endl;
   cin>>choice;
   general(myarray,content,choice);

    return 0;
}
void general(int*myarray,int content,int choice){
    if(choice==8)
        return;
    else{
            switch (choice){
            case 1:
                cout<<mode(myarray,content)<<endl;
                break;
            case 2:
                cout<<median(myarray,content)<<endl;
                break;
            case 3:
                cout<<mean(myarray,content)<<endl;
                break;
            case 4:
                cout<<"if you want to sort in an ascending order,enter 1"<<endl;
                cout<<"if you want to sort in a descending order ,enter 0"<<endl;
                bool x;
                cin>>x;
                sorting(myarray,content,x);
                break;
            case 5:
                cout<<range(myarray,content)<<endl;
                break;
            case 6:
                frequency(myarray,content);
                break;
            case 7:
                cout<<"enter the number of elements you want the shift to happen to"<<endl;
                int y;
                cin>>y;
                shift(myarray,content,y);
                break;
            default:
                cout<<"incorrect input , try again later"<<endl;
                break;
    }
    }
  cout<<"enter the size of the array"<<endl;
  int cont,ch;
  cin>>cont;
  cout<<"enter the elements of the array but,only positive values"<<endl;
  int *myarra;
  myarra=new int [cont];
  for(int i=0;i<cont;i++)
        cin>>myarra[i];
   cout<<"now choose one of the following "<<endl;
   cout<<"1-Mode"<<endl;
   cout<<"2-Median"<<endl;
   cout<<"3-Mean"<<endl;
   cout<<"4-sort"<<endl;
   cout<<"5-Range"<<endl;
   cout<<"6-Element frequency"<<endl;
   cout<<"7-Element circular shifter"<<endl;
   cout<<"8-Exit"<<endl;
   cout<<endl;
   cin>>ch;
   general(myarra,cont,ch);
}
int mode(int*myarray,int content){
    int x=0;
    int *newarray=new int [content];
    int y=myarray[0];
    for(int i=0;i<content;i++){
        y=myarray[i];
        x=0;
        for(int j=0;j<content;j++){
            if(y==myarray[j]){
                x=x+1;
          }
        }
        newarray[i]=x;
    }
    int z=newarray[0];
    int temp=-2;
    for(int m=1;m<content;m++){
       if(z<newarray[m]){
        z=newarray[m];
        temp=m;
       }
       else
        continue;
    }
    int v=1;
    for(int n=1;n<content;n++){
        if(newarray[0]==newarray[n]){
            v=v+1;
        }
    }
    if(v==content)
        temp=-2;
    if(temp==-2 && (v==content))
        return -1;
    if(z==newarray[0] && temp==-2){
        return myarray[0];
    }
    if(temp!=-2)
        return myarray[temp];
}
float median(int*myarray,int content){
while(1){
    int swapped=0;
for(int i=0;i<(content-1);i++){
    if(myarray[i]>myarray[i+1]){
            int temp=myarray[i];
            myarray[i]=myarray[i+1];
            myarray[i+1]=temp;
            swapped=1;

    }
}
if(swapped==0)
    break;
}
    if(content%2!=0)
        return myarray[(content/2)];
    else{
        int m=myarray[(content/2)-1];
        float n=(m+myarray[content/2])/2.0;
        return n;
    }
}
float mean(int*myarray,int content){
int sum=0;
float average;
for(int i=0;i<content;i++)
    sum=sum+myarray[i];
average=sum/float(content);
return average;
}
void sorting(int*myarray,int content,bool x){
if(x==1){
    while(1){
    int swapped=0;
for(int i=0;i<(content-1);i++){
    if(myarray[i]>myarray[i+1]){
            int temp=myarray[i];
            myarray[i]=myarray[i+1];
            myarray[i+1]=temp;
            swapped=1;

    }
}
if(swapped==0)
    break;
}
}
else if(x==0){
    while(1){
    int swapped1=0;
for(int j=0;j<(content-1);j++){
    if(myarray[j]<myarray[j+1]){
            int temp=myarray[j];
            myarray[j]=myarray[j+1];
            myarray[j+1]=temp;
            swapped1=1;

    }
}
if(swapped1==0)
    break;
}
}
for(int j=0;j<content;j++)
    cout<<myarray[j]<<endl;
}
int range(int*myarray,int content){
int minelement=myarray[0];
for(int i=1;i<content;i++){
    if(minelement>myarray[i])
        minelement=myarray[i];
}
int maxelement=myarray[0];
for(int j=1;j<content;j++){
    if(maxelement<myarray[j])
        maxelement=myarray[j];
}
int diff;
diff=maxelement-minelement;
return diff;
}
void frequency(int*myarray,int content){
 int x=0;
    int *newarray=new int [content];
    int y=myarray[0];
    for(int i=0;i<content;i++){
        y=myarray[i];
        x=0;
        for(int j=0;j<content;j++){
            if(y==myarray[j]){
                x=x+1;
          }
        }
        newarray[i]=x;
    }
int c=0;
for(int m=0;m<content;m++){
        c=0;
    for(int o=0;o<m;o++){
        if(myarray[m]==myarray[o])
            c=100;
    }
    if(c==0)
    cout<<myarray[m]<<"\t";
}
cout<<endl;
int b=0;
for(int n=0;n<content;n++){
        b=0;
      for(int g=0;g<n;g++){
        if(newarray[n]==newarray[g] && myarray[n]==myarray[g])
            b=100;
      }
    if(b==0)
    cout<<newarray[n]<<"\t";
}
cout<<endl;
}
void shift(int*myarray,int content,int y){
int m=0;
int n=0;
int*temparray;
temparray=new int [content];
for(int j=0;j<content;j++)
    temparray[j]=myarray[j];
if(y>=1 && y<=content-1){
        for(int i=y;i>=0;i--){
           myarray[m]=myarray[content-i];
           m=m+1;
        }
        for(int t=y;t<(content-y);t++){
            myarray[t+y]=temparray[t];
        }
        int temp=y;
        for(int a=0;a<y;a++){
            myarray[temp]=temparray[a];
            temp=temp+1;

        }
        for(int u=0;u<content;u++)
            cout<<myarray[u]<<"\t";
        cout<<endl;
}
else
    cout<<"NULL"<<endl;
}














