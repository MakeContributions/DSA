let sort = [12,6,3,88,1,4,8];

for(let i = 0; i<sort.length; i++){
    let key = sort[i];
    let j = i-1;
    //comparing keys with other elements
    while(key<sort[j] && j>=0){
        sort[j+1]=sort[j];
        j--;
    }
    sort[j+1]=key;
}
console.log(sort)