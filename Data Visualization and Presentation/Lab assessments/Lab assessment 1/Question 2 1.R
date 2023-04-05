library(tidyverse)
library(dplyr)
library(gapminder)

gapminder%>% filter(year == 1952)%>% arrange(desc(gdpPercap))
arrange(filter(gapminder, year == 1952), desc(gdpPercap))
gapminder %>% filter(year == 1992, continent == 'Europe')%>% arrange(desc(pop))
gapminder %>% mutate(pop = pop / 1000000)

ggplot(gapminder) + geom_point(mapping = aes(x = gdpPercap, y = lifeExp)) + ggtitle("Afraaz Hussain | 20BDS0374")