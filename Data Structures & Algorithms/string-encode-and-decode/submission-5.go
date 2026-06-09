type Solution struct{}

func (s *Solution) Encode(strs []string) string {
    var res strings.Builder
    for _, str:= range strs{
        s := strconv.Itoa(len(str)) + "#" + str

        res.WriteString(s)
    }

    //fmt.Println(res.String())
    return res.String()
}

func (s *Solution) Decode(encoded string) []string {
    l,r := 0,0
    res := make([]string,0)
    for r < len(encoded) {
        for encoded[r] != '#'{
            r += 1
        }
        //fmt.Println(r)
        length,_ := strconv.Atoi(encoded[l:r])
        //fmt.Println(length)
        str := encoded[r+1:r + 1 + length]
        //fmt.Println(str)
        res = append(res, str)
        
        r += length + 1
        l = r
    }
    return res
}
