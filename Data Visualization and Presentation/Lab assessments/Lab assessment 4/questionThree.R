# Load the required packages
library(arules)

# Read the data as a transaction dataset
dataset <- read.transactions("Market_Basket_Optimisation.csv", sep = ",")

# Perform Market Basket Analysis with Apriori algorithm
rules <- apriori(dataset, parameter = list(supp = 0.005, conf = 0.5))

# Inspect the top 10 rules
inspect(head(rules, n = 10))
