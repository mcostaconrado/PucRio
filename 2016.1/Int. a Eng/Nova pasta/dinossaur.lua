dinossaur={}

function dinossaur.load()
  Dino={
    x = screenWidth/2,
    y = screenHeight/2,
    goingToRight = true,
    velocity = 70,
    img = love.graphics.newImage("dino1.png")
  }
  running = newAnimation(Dino.img, 64, 67, 0.15, 0)
end