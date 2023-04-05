# Load the required packages
library(shiny)
library(dplyr)
library(ggplot2)
library(gapminder)

# Define the user interface
ui <- fluidPage(
  # Add a title to the dashboard
  titlePanel("Gapminder Dashboard"),
  
  # Add a sidebar panel with input options
  sidebarLayout(
    sidebarPanel(
      # Add a dropdown menu for selecting the continent
      selectInput("continent", "Select a Continent",
                  choices = c("Asia", "Europe", "Africa", "Americas", "Oceania")),
      
      # Add a slider for selecting the year range
      sliderInput("year_range", "Select a Year Range",
                  min = min(gapminder$year), max = max(gapminder$year),
                  value = c(min(gapminder$year), max(gapminder$year)), step = 5),
      
      # Add a checkbox for showing/hiding the life expectancy trendline
      checkboxInput("trendline", "Show Life Expectancy Trendline", value = TRUE),
      
      # Add a text output for displaying your name and admission number
      textOutput("info")
    ),
    
    # Add the main panel for displaying the plots
    mainPanel(
      # Add a plot for displaying the population vs GDP per capita for the selected continent
      plotOutput("pop_gdp_plot")
    )
  )
)

# Define the server
server <- function(input, output) {
  # Create a reactive dataset for the selected continent and year range
  continent_data <- reactive({
    gapminder %>% filter(continent == input$continent & year >= input$year_range[1] & year <= input$year_range[2])
  })
  
  # Create a plot for displaying the population vs GDP per capita for the selected continent and year range
  output$pop_gdp_plot <- renderPlot({
    ggplot(continent_data(), aes(x = gdpPercap, y = pop, size = lifeExp, color = year)) +
      geom_point(alpha = 0.7) +
      scale_x_log10() +
      scale_size(range = c(2, 20)) +
      labs(x = "GDP per capita", y = "Population", size = "Life Expectancy", color = "Year") +
      theme_classic() +
      # Add a trendline for the life expectancy
      if(input$trendline) geom_smooth(method = "lm", se = FALSE)
  })

  output$info <- renderText({
    paste("Afraaz Hussain | 20BDS0374")
  })
}

# Run the application
shinyApp(ui = ui, server = server)
