let userInput = prompt("Please enter number:");
let number= parseInt(userInput);

if( number % 3 == 0 && number % 5 == 0){// checking by both number
    console.log("FizzBuzz");}
else if (number % 3 == 0){
console.log("Fizz");}// checking by 3
else if (number % 5 == 0){
console.log("Buzz");}// checking by 5
else{
console.log(number);// if not divisible by 3 or 5
}
