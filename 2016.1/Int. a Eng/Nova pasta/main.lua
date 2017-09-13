require("AnAL")
require("dinossaur")

function love.load()
  
  love.window.setFullscreen(true, "desktop")
  
  icon=love.graphics.newImage("Chrome.png")
  iconWidth = icon:getWidth()
  iconHeight = icon:getHeight()
  screenWidth = love.graphics.getWidth()
  screenHeight = love.graphics.getHeight()
  state = not love.mouse.isVisible()
  GameOver = false; 
  points = 0
  background = love.graphics.newImage("Background.png")
  dinossaur.load()
end

  Dots ={
    x=0,
    y=0,
    width = 3,
    height = 3    
  }



function CheckBoxCollision(x1,y1,w1,h1,x2,y2,w2,h2)
  return x1 < x2+w2 and x2 < x1+w1 and y1 < y2+h2 and y2 < y1+h1
end

function math.getAngle(x1,y1, x2,y2)
  return math.atan2(y2-y1, x2-x1)
end

function love.keypressed(key)
   if key == "r" then
      playAgain = 1
   end
end

function love.update(dt)
  
  
  if not GameOver then
    playAgain=0
    running:update(dt)
    love.mouse.setVisible(state)
    
    Mouse_x = love.mouse.getX()
    Mouse_y = love.mouse.getY()
    if CheckBoxCollision(Mouse_x, Mouse_y, iconWidth, iconHeight, Dino.x, Dino.y, 64, 67) then
      GameOver = true
    end

    local angle = math.getAngle(Dino.x, Dino.y, Mouse_x, Mouse_y)
    local dx = math.cos(angle) * (dt * Dino.velocity)
    local dy = math.sin(angle) * (dt * Dino.velocity)
    Dino.x = Dino.x + dx
    Dino.y = Dino.y + dy
  else
    if playAgain == 1 then
      GameOver = false
    end
  end
end

function love.draw()
  
  
  love.graphics.rectangle("fill", Dots.x, Dots.y, Dots.width, Dots.height)
  if not GameOver then
    love.graphics.draw(background,0,0,0,(screenWidth/background:getWidth()), (screenHeight/background:getHeight()))
    love.graphics.setColor(255,255,255)
    running:draw(Dino.x, Dino.y)
    love.graphics.draw(icon, Mouse_x, Mouse_y)

    love.graphics.print(math.floor(points), 300, 300)
  else
    love.graphics.setColor(255,255,255)
    love.graphics.draw(background,0,0,0,(screenWidth/background:getWidth()), (screenHeight/background:getHeight()))
    love.graphics.setColor(255,100,100)
    love.graphics.print("GAME OVER", 300, 300)
  end
end