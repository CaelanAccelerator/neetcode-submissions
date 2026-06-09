func isValid(s string) bool {
    st := make([]rune, 0)
    index := 0
    for _, c := range s{
        if c == ')' {
            if index == 0 || st[index - 1] != '('{
                return false
            }
            st = st[:index - 1]
            index -= 1
        }else if c == ']'{
            if index == 0 || st[index - 1] != '['{
                return false
            }
            st = st[:index - 1]
            index -= 1
        }else if c == '}'{
            if index == 0 || st[index - 1] != '{'{
                return false
            }
            st = st[:index - 1]
            index -= 1
        }else{
            st = append(st, c)
            index += 1
        }
    }
    return index == 0

}


