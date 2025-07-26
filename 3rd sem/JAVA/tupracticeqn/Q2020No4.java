//wite a java program to print first n prime number ;
import java.util.Scanner;
public class Q2020No4 {
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.println("Enter the number of prime number you want to print");
int n = sc.nextInt();
int count = 0;
int i = 2;
while(count < n){
if(isPrime(i)){
System.out.print(i + " ");
count++;
}
i++;
}
}
public static boolean isPrime(int n){
for(int i = 2; i <= n/2; i++){
if(n % i == 0){
return false;
}}
return true;
}
}