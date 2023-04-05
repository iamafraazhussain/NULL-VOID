# Load the required packages
library(tidyverse)

# Read the data
dataset <- read.csv("Mall_Customers.csv")
# Convert the 'Genre' column from character to factor
dataset$gender <- as.factor(dataset$gender)

# Perform K-means clustering with 5 clusters
set.seed(123)
kmeans_clusters <- kmeans(dataset[, c("age", "annualIncome", "spendingScore")], centers = 5)

# Add cluster assignments to the original data
dataset$cluster <- kmeans_clusters$cluster

# Plot the clusters
ggplot(dataset, aes(x = `annualIncome`, y = `spendingScore`, color = factor(cluster))) +
  geom_point() +
  xlab("Annual Income (k$)") +
  ylab("Spending Score (1-100)") +
  ggtitle("Afraaz Hussain | 20BDS0374")
