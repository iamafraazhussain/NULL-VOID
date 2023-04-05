ui<- {library(shiny)
library(shinydashboard)
shinyServer(
  pageWithSidebar(
    headerPanel("My First App"),
    sidebarPanel(
      selectInput("Distribution",
                  'Pls.select Distribution type',
                  choice = c('Normal', 'Exponential')),
      sliderInput("sampleSize",
                  'Pls.Select Sample Size',
                  min=100,max=5000,
                  value=100, step = 100),
      conditionalPanel(condition =
                         "input.Distribution=='Normal'",
                       textInput("mean","Pls.select mean:",
                                 10),
                       textInput("sd","Pls.select SD:",3)),
      conditionalPanel(condition =
                         "input.Distribution=='Exponential'",
                       textInput("lambda","Pls.select Exp lambda:",
                                 1))
      
    ),
    mainPanel(plotOutput('myPlot'))
    
  )
)
}

server <- {shinyServer(
  function(input,output,session){
    output$myPlot <- renderPlot({
      disType = input$Distribution
      size <- input$sampleSize
      if(disType == "Normal"){
        randomVec=rnorm(size,mean=as.numeric(input$mean),
                        
                        sd=as.numeric(input$sd))
      }
      else{
        randomVec=rexp(size,
                       rate = 1/as.numeric(input$lambda))
      }
      hist(randomVec,col="blue")
    })
  }
)
}

runApp(ui,server)
