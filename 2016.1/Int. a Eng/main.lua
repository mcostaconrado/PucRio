function love.load()
  px = 0
end

function love.update(dt)
  if px >= 800 then
    left = false
  elseif px <=0 then
    left = true
  end
  
  if left then
    px = px + 300*dt
  else
    px = px - 300*dt
  end
end

function love.draw()
  love.graphics.print("Hello World", px , 300)
end