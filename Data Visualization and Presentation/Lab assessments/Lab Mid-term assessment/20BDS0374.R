myData <- read.csv('HRDataset_v14.csv')
View(myData)


library(ggplot2)
library(gridExtra)



# Uni-variate graph plot
uniVariateDensityPlot <- ggplot(data = myData, aes(x = myData$EmpStatusID)) + geom_density() + 
  labs(title = "Afraaz Hussain | 20BDS0374", x = "Employee status ID")

uniVariateHistogram <- hist(myData$Salary, col = "purple", breaks = 15, xlab = "Employee salary")

uniVariateBarPlot <- barplot(table(myData$EmpSatisfaction), col = "purple", xlab = "Employee satisfaction", ylab = "Frequency")



# Bi-variate graph plot
biVariateDensityPlot <- ggplot(data = myData, aes(x = EmpStatusID)) +
  geom_density(aes(fill = factor(myData$Sex), alpha = 0.5)) + 
  labs(title = "Afraaz Hussain | 20BDS0374", x = "Employee status ID")

biVariateBarPlot <- boxplot(myData$ManagerID~myData$EmpStatusID, data = myData, col = "purple", title = "Afraaz Hussain | 20BDS0374", xlab = "Employee status ID", ylab = "Manager ID")

biVariatePlot <- with(myData, plot(ManagerID, EmpStatusID))



# Multivariate graph plot
multiVariatePlot <- ggplot(data = myData) + geom_point(mapping = aes(x = myData$ManagerID, y = myData$EmpStatusID, color = myData$EmpSatisfaction)) + 
  labs(title = "Afraaz Hussain | 20BDS0374", x = "Employee manager ID", y = "Employee status ID", col = "Employee satisfaction")

multiVariatePlotTwo <- ggplot(data = myData) + geom_point(mapping = aes(x = myData$RecruitmentSource, y = myData$EmpStatusID, color = myData$EmpSatisfaction)) + 
  labs(title = "Afraaz Hussain | 20BDS0374", x = "Recruitment source", y = "Employee status ID", col = "Employee satisfaction")

multiVariatePlotThree <- ggplot(data = myData) + geom_point(mapping = aes(x = myData$PerformanceScore, y = myData$EngagementSurvey, color = myData$EmpSatisfaction)) + 
  labs(title = "Afraaz Hussain | 20BDS0374", x = "Performance score", y = "Engagement", col = "Employee satisfaction")



grid.arrange(uniVariateDensityPlot, uniVariateHistogram, uniVariateBarPlot, biVariateDensityPlot, biVariateBarPlot, biVariatePlot, multiVariatePlot, multiVariatePlotTwo, multiVariatePlotThree,  nrow = 3, top = "A 3 by 3 matrix consisting of 3 different plots")
