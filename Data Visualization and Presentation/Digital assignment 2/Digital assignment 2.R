library(shiny)
library(tidyverse)

# Load the data
df <- read.csv("VehicleFailureData.csv")

# Remove commas and convert Mileage_at_Failure to numeric
df$Mileage_at_Failure <- as.numeric(gsub(",", "", df$Mileage_at_Failure))

# Define UI
ui <- fluidPage(
  titlePanel("Vehicle Failure Data"),
  sidebarLayout(
    sidebarPanel(
      selectInput(inputId = "state",
                  label = "Select State:",
                  choices = unique(df$State),
                  selected = "CA"),
      sliderInput(inputId = "mileage",
                  label = "Mileage Range:",
                  min = 0,
                  max = 50000,
                  value = c(10000, 30000)),
      checkboxInput(inputId = "failed",
                    label = "Show Failed Vehicles Only",
                    value = FALSE),
      hr(),
      helpText("Created by Afraaz Hussain (Admission Number: 20BDS0374)")
    ),
    mainPanel(
      plotOutput(outputId = "scatterplot"),
      tableOutput(outputId = "table")
    )
  )
)

# Define server
server <- function(input, output) {
  
  # Filter data based on inputs
  filteredData <- reactive({
    df %>%
      filter(State == input$state,
             Mileage_at_Failure >= input$mileage[1],
             Mileage_at_Failure <= input$mileage[2]) %>%
      if(input$failed) filter(Failure_Month > 0) else .
  })
  
  # Scatter plot
  output$scatterplot <- renderPlot({
    ggplot(filteredData(), aes(x = Mileage_at_Failure, y = Labor_Cost)) +
      geom_point()
  })
  
  # Table
  output$table <- renderTable({
    filteredData() %>%
      select(Vehicle_Number, State, Failure_Month, Mileage_at_Failure, Labor_Cost) %>%
      head(10)
  })
}

# Run the app
shinyApp(ui = ui, server = server)
