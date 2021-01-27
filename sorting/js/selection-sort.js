let sort = [12,6,3,88,1,4,8]

for(let i=0; i<sort.length; i++){
    for(let j=0; j<sort.length; j++){
        // comparing array elements
        if(sort[j]>sort[i]){
            //swaping elements
            let temp = sort[i];
            sort[i]=sort[j];
            sort[j]= temp;
        }
    }
}

console.log(sort)