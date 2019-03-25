import pandas as pd
import quandl
def main():
    df = quandl.get('WIKI/GOOGL')
    #df = quandl.get("BCIR/_VXGO", authtoken="DATF15A5Xb1ijrPSQi9g")
    
    
    df = df[['Adj. Open', 'Adj. High','Adj. Low','Adj. Close','Adj. Volume']]
    df['HL_PCT'] = ((df['Adj. High'] - df['Adj. Low'])/df['Adj. Low'])*100.0
    df['PCT_change'] = ((df['Adj. Close'] - df['Adj. Open'])/df['Adj. Open'])*100.0
 

    df = df[['Adj. Open','HL_PCT','PCT_change','Adj. Volume']]
    print df


main()
