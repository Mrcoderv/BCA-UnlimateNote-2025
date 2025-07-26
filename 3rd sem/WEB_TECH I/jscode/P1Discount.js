function Discount(){
let userInput = prompt("Please enter purchase value :");
let purchaseValue = parseFloat(userInput);
    let discount = 0;
    if (purchaseValue >= 10000) {
        discount = 0.2;
    } else if (purchaseValue >= 5000|| purchaseValue < 10000) {
        discount = 0.1;
    }
    
    let discountAmount = purchaseValue * discount;
    let finalAmount = purchaseValue - discountAmount;
    console.log("Discounted amount: " + discountAmount);
    console.log("Final amount: " + finalAmount);
    document.write("Discounted amount: " + discountAmount);
    document.write("Final amount: " + finalAmount);
}