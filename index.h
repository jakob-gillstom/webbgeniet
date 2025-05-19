<!DOCTYPE html>
<html lang="sv">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Webbgeniet</title>
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 0;
      padding: 0;
      background: linear-gradient(120deg, #1e3c72, #2a5298);
      color: white;
      display: flex;
      flex-direction: column;
      align-items: center;
    }
    header {
      background-color: rgba(0, 0, 0, 0.2);
      width: 100%;
      padding: 1rem;
      text-align: center;
    }
    h1 {
      font-size: 3rem;
      margin: 0.5rem 0;
    }
    main {
      max-width: 600px;
      width: 90%;
      padding: 2rem;
      background-color: rgba(255, 255, 255, 0.1);
      border-radius: 15px;
      box-shadow: 0 0 10px rgba(0,0,0,0.3);
      margin: 2rem 0;
    }
    label {
      display: block;
      margin: 1rem 0 0.3rem;
    }
    input, textarea {
      width: 100%;
      padding: 0.5rem;
      border: none;
      border-radius: 5px;
    }
    button {
      margin-top: 1rem;
      padding: 0.7rem 1.5rem;
      background-color: #00c6ff;
      border: none;
      border-radius: 5px;
      font-size: 1rem;
      cursor: pointer;
    }
    .thank-you {
      display: none;
      text-align: center;
      font-size: 1.2rem;
      background-color: rgba(0,0,0,0.3);
      padding: 1.5rem;
      border-radius: 10px;
      margin-top: 2rem;
    }
  </style>
</head>
<body>
  <header>
    <h1>Webbgeniet</h1>
    <p>Jag bygger hemsidor som glänser!</p>
  </header>
  <main>
    <form id="contactForm" action="https://formspree.io/f/manovrze" method="POST">
      <label for="name">Namn:</label>
      <input type="text" id="name" name="name" required />

      <label for="email">E-post:</label>
      <input type="email" id="email" name="email" required />

      <label for="message">Meddelande:</label>
      <textarea id="message" name="message" rows="4" required></textarea>

      <button type="submit">Skicka</button>
    </form>

    <div class="thank-you" id="thankYouMessage">
      ✅ Tack! Ditt meddelande har skickats.<br />
      Jag kontaktar dig så snart jag kan och börjar jobba på din hemsida!
    </div>
  </main>

  <script>
    const form = document.getElementById('contactForm');
    const thankYouMessage = document.getElementById('thankYouMessage');

    form.addEventListener('submit', function(event) {
      event.preventDefault();
      const formData = new FormData(form);
      fetch(form.action, {
        method: 'POST',
        body: formData,
        headers: {
          'Accept': 'application/json'
        }
      }).then(response => {
        if (response.ok) {
          form.style.display = 'none';
          thankYouMessage.style.display = 'block';
        } else {
          alert("Något gick fel. Försök igen!");
        }
      }).catch(error => {
        alert("Ett fel uppstod. Kontrollera din internetanslutning.");
      });
    });
  </script>
</body>
</html>
