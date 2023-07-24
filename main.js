function generate(){
    var array= document.getElementById("mainin").value.split("");
    document.getElementById("out").innerHTML=getOrderedCombinations(array).join('<br>');
}

function getPermutations(arr) {
    if (arr.length === 1) {
      return [arr];
    }
  
    const result = [];
  
    for (let i = 0; i < arr.length; i++) {
      const currentElement = arr[i];
      const remainingElements = arr.slice(0, i).concat(arr.slice(i + 1));
      const permutationsOfRemaining = getPermutations(remainingElements);
  
      for (let j = 0; j < permutationsOfRemaining.length; j++) {
        result.push(currentElement + permutationsOfRemaining[j]);
      }
    }
  
    return result;
  }
  
  function getOrderedCombinations(arr) {
    const permutations = getPermutations(arr);
    const orderedCombinations = [];
  
    for (let i = 0; i < permutations.length; i++) {
      if (permutations[i].length === arr.length) {
        orderedCombinations.push(permutations[i]);
      }
    }
  
    return orderedCombinations;
  }