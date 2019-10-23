'''Challenge 1 – Mortgage Repayments
A common question asked by customers at a firm is about payments on mortgages. 
Customers would like to know what their total estimated cost will be, before signing the contract. 
A team has spotted this, and would like to develop a new tool that allows users to calculate this value for 
firm’s new mortgage type, “Simply Buy”.
Your task is to develop a method calculateTotalPayment, which takes in three integers – the initial level 
of debt, the percentage interest, and the percentage repayment,and returns a single integer representing 
the total cost of the mortgage. Repayment is a fixed percentage of the initial debt, and the interest is a
percentage of the current debt.For the “Simply Buy” mortgage, there is a fixed 10% deposit, which should be
included in the total payment, and each month interest is added before a repayment is made. 
There is also a minimum repayment of $50 (if the repayment for a month is less than $50, then it will be rounded up to $50).'''
def question01(initialLevelOfDebt, interestPercentage, repaymentPercentage):
    # modify and then return the variable below
    import math
    answer = -5
    fixed_repayment=initialLevelOfDebt/10
    i=(interestPercentage/100)
    k=i+1
    r=(initialLevelOfDebt*repaymentPercentage)/100
    t=(50*i-k*r)/(initialLevelOfDebt*k-initialLevelOfDebt-r)
    n=int(math.log(t,k))        
    answer=n*r + fixed_repayment + ((k**n)*((initialLevelOfDebt*i)-r) +r*k)/i -r
    return int(answer)

