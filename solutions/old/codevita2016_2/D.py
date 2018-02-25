from datetime import date
import sys

def days(c):
    return (c-date(1,1,1)).days
def yeardays(c):
    return (c-date(c.year,1,1)).days+1

def stars(d, st):
        ndays = days(d)
        if(ndays%4==3):
            return 0
        wd = ndays%7
        wd = (wd+st)%7
        if wd >= 5:
            return 0
        return min(50, yeardays(d))
    
    
if __name__ == '__main__':
    wd = input()
    daymap = {
        'Monday': 0,
        'Tuesday': 1,
        'Wednesday': 2,
        'Thursday': 3,
        'Friday': 4,
        'Saturday': 5,
        'Sunday': 6,
    }
    if wd in daymap:
        wd = daymap[wd]
        try:
            d = input()
            if d!='':
                d = date(*reversed(list(map(int,d.split('/')))))
            sys.stdout.write(str(stars(d,wd)))
        except ValueError:
            sys.stdout.write('Invalid Date')
    else:
        sys.stdout.write('Invalid Day')
    sys.stdout.flush()
    
    