# ding_redia_messages

A module for receiving Service Messages from Redia.

Service Messages are a way of showing small messages for the user on different platforms. The library app, self service devices and in DDBCMS.
These messages are made i the Redia Admin interface and sent to different platforms. The messages can be manually set or generated automatically.
For instance if a backend service is down.

The module receivies PUB/SUB google messages from the Redia Service Message server. It receives a complete list off the messages to show
and stores them. When a new list off messages is received the old list is discarded and the new one saved.

A message has following format:

{
    "category": "manual",
    "header": "Lukket",
    "body": "Biblioteket er midlertidigt lukket pga. vandskade.",
    "level": "info",
    "dismissible": true,
    "link_title": "Gå til Google",
    "link_url": "www.google.dk",
    "time_begin": 1669110228,
    "time_end": 1677414953
}

The messages are then displayed on the frontpage if it is their time to be shown The messages can be very time critical so we need to bypass caching
off the frontpage. Therefore we use ajax call to check if there is a message to be shown.

A list of all messages is here: /admin/config/ding/ding_redia_messages
