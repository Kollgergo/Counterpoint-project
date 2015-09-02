class ScoreViewModel {
    Score& score;
    
    set/get/add minden legyen. 
    clef / elojegyzes vector, ezekhez get/set, stb (add, remove, stb ezeket is piszkalja)
    
    getPosition(staffnumber, notenumber) -> vertikalisan hol int kozepso vonaltol
    getAccent(staffnum, notenum) -> kell-e plusz elojegyzes neki enum: bb, b, semmi, #, ##
    getType (staffnum, notenum) -> egesz, negyed, folfele vagy lefele
    
    esetleg ez a harom adat egy fuggvennyel egy strukturaban. 
    
    
    
};
