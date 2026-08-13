function Posneg(){

    let pos = 0;
    let neg = 0;

    for (let i = 0; i< 4; i++){
        let Num = parseInt(prompt(`N${i}`));
        if (Num >= 0){
            pos++;
        } else {
            neg++
        }
    }

    return `${pos}(+) e ${neg}(-)`
}