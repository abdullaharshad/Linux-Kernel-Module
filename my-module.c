#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/moduleparam.h>
#include<linux/stat.h>

//variable declaration
static int array_size = 10;

//Explicit parameter declaration as part of the command line args 
module_param(array_size,int,0);

MODULE_PARM_DESC(array_size,"size of the array");

static char *mystr="blah";

module_param(mystr,charp,0000);

MODULE_PARM_DESC(mystr,"Palindrome string");

static int array[10]={1,2,3,4,5,6,7,8,9,10};

module_param_array(array,int,&array_size,0000);

MODULE_PARM_DESC(array,"An array of numbers");



static int __init initialise_saber(void)
{
int i,j,sum=0,product=1,fac=1,pal=1,prime=1;

for(i=0;i<array_size;i++)
{sum+=array[i];product*=array[i];}

for(i=1;i<=array_size;i++)
{fac*=i;}

for(i=2;i<=array_size/2;i++)
{ if(array_size % i == 0){ prime=0; break; }
}

if(prime==1) printk(KERN_INFO "%d IS A PRIME NUMBER\n",array_size);
else printk(KERN_INFO "%d IS NOT A PRIME NUMBER\n",array_size);

j=0;
while (mystr[j]!='\0') j++;
j--;

i=0;
while(i<j)
{
if(mystr[i]!=mystr[j]) {pal=0;printk(KERN_INFO "i:%d,j:%d\n",i,j);break;}
i++;j--;
}

if(pal==1) printk(KERN_INFO "%s IS A PALINDROME\n",mystr);
else printk(KERN_INFO "%s IS NOT A PALINDROME\n",mystr);

printk(KERN_INFO "sum is %d\nproduct is %d\nfactorial is %d\n",sum,product,fac);

return 0;
}


static void __exit drop_saber(void)
{
printk(KERN_INFO "Alas we had sum and product and its over now!!\nAnd the result of palindorme too\n");
}


module_init(initialise_saber);
module_exit(drop_saber);

//Licensing information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("anishsharma1996@gmail.com");
MODULE_DESCRIPTION("Module with command line arguments"); 



















