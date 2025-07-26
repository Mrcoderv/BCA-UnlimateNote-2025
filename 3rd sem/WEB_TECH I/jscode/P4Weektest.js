let userInput = prompt("Please enter day of week :");
let day = userInput.toLowerCase();
switch (day) {
    case "monday":
        console.log("Start of the workweek");
        break;  
    case "friday":
        console.log("Almost weekend");
        break;
    case "sunday":
    case "saturday":
        console.log("Weekend");
        break;
    case "tuesday":
    case "wednesday":   
    case "thursday":
        console.log("Midweek");
        break;
    default:    
        console.log("Invalid input day");
        break; 
}