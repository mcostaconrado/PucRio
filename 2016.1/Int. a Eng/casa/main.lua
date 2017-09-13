
tela = {
  width = love.graphics.getWidth();
  height = love.graphics.getHeight()
}

cursor = {
  x = love.mouse.getX();
  y = love.mouse.getY()
}

sol = {
  x=80;
  velocidade = 100
}

nuvem = {
  velocidade = 18;
  x = 296  
}

janela = {
  r= 0;
  g= 50;
  b= 100;
}

background = {
  r= 102;
  g= 178;
  b= 255
}


function love.load()
  
  
end

function love.update(dt)
  cursor.x = love.mouse.getX()
  cursor.y = love.mouse.getY()
  
  
  if nuvem.x >= 860 then -- nuvem voltando
    nuvem.x = - 420
  else
    nuvem.x = nuvem.x + nuvem.velocidade*dt
  end
  
  if sol.x >= 960 then
    if sol.x < 1200 then
      sol.x = sol.x + sol.velocidade*dt
      background.r = 0
      background.g = 0
      background.b = 0
      janela.r = 255
      janela.g = 255
      janela.b = 0
    elseif sol.x >= 1200 then
      sol.x = -160
      background.r = 102
      background.g = 178
      background.b = 255
      janela.r = 0
      janela.g = 50
      janela.b = 100
    end
  else
    sol.x = sol.x + sol.velocidade*dt
  end
end

function love.draw()
  --love.graphics.print(cursor.x, 20, 20)
  --love.graphics.print(cursor.y, 20, 32)
  
  love.graphics.setBackgroundColor (background.r, background.g, background.b)
  love.graphics.setColor (0, 201, 7)
  love.graphics.rectangle ("fill", 0, tela.height - 130, tela.width, 130) -- chão
  love.graphics.setColor (96, 96, 96)
  love.graphics.rectangle ("fill", 75, tela.height - 230, 150, 120) -- casa
  love.graphics.setColor (201, 0, 0)
  love.graphics.polygon ("fill", 70, tela.height - 225, 150, 300, 230, tela.height - 225) -- telhado
  love.graphics.setColor (102, 51, 0)
  love.graphics.rectangle ("fill", 170, 440, 30, 50) -- porta
  love.graphics.setColor (103, 103, 103)
  love.graphics.circle ("fill", 176, 463, 2.5, 200) -- maçaneta
  love.graphics.setColor (janela.r, janela.g, janela.b)--janela
  love.graphics.rectangle ("fill", 93, 394, 40, 30)
  love.graphics.setColor (0, 0, 0)
  love.graphics.setLineWidth (2)
  love.graphics.rectangle ("line", 93, 394, 40, 30)
  love.graphics.rectangle ("line", 93, 394, 20, 15)
  love.graphics.rectangle ("line", 113, 394, 20, 15)--fim janela
  love.graphics.setColor (102, 51, 0)
  love.graphics.rectangle ("fill", 545, 380, 50, 180)--tronco
  love.graphics.setColor (0, 120, 0)
  love.graphics.circle ("fill", 520, 350, 70, 40)--folhas
  love.graphics.circle ("fill", 620, 350, 70, 40)
  love.graphics.circle ("fill", 570, 260, 70, 40)--fim folhas
  love.graphics.setColor (255, 255, 0)
  love.graphics.circle ("fill", sol.x, 85, 45, 200)--sol
  love.graphics.setLineWidth (5)
  love.graphics.line (sol.x, 5, sol.x, 165)
  love.graphics.line (sol.x - 80, 85, sol.x + 80, 85)
  love.graphics.line (sol.x - 80*math.sqrt(2)/2, 85 - 80*math.sqrt(2)/2, sol.x + 80*math.sqrt(2)/2, 85 + 80*math.sqrt(2)/2)--raios
  love.graphics.line (sol.x - 80*math.sqrt(2)/2, 85 + 80*math.sqrt(2)/2, sol.x + 80*math.sqrt(2)/2, 85 - 80*math.sqrt(2)/2)
  love.graphics.setColor (255, 255, 255)
  love.graphics.circle ("fill", nuvem.x, 78, 45, 200)--nuvens
  love.graphics.circle ("fill", nuvem.x + 42, 75, 42, 200)
  love.graphics.circle ("fill", nuvem.x + 84, 78, 44, 200)
end