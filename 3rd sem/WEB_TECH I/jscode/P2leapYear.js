let userInput = prompt("Please enter Year :");
let year = parseInt(userInput);
      if (year % 400 == 0) {
    console.log("Year is a leap year");
} else if (year % 4 == 0 && year % 100 != 0) {
    console.log("Year is a leap year");
} else {
    console.log("Year is not a leap year");
}

