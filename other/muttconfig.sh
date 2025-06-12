#!/usr/bin/env bash

echo "1 - Gmail"
echo "2 - iCloud Mail"
echo "3 - Outlook"
read -p "Enter your provider's number: " prov
read -p "Enter your email address: " addr
read -p "Enter your password (App-Specific Password may be required): " pass
read -p "Enter the real name to show up on emails sent: " name

if [ "$prov" = "1" ]; then
    smtps="smtp.gmail.com"
    smtpp="587"
    imaps="imap.gmail.com"
    imapp="993"
elif [ "$prov" = "2" ]; then
    smtps="smtp.mail.me.com"
    smtpp="587"
    imaps="imap.mail.me.com"
    imapp="993"
elif [ "$prov" = "3" ]; then
    smtps="smtp.office365.com"
    smtpp="587"
    imaps="outlook.office365.com"
    imapp="993"
else
    echo "Unknown provider selected."
    exit 1
fi

mkdir -p ~/.mycal/mail

cat > ~/.mycal/mail/.muttrc <<EOF
set ssl_starttls=yes
set ssl_force_tls=yes

set imap_user = "$addr"
set imap_pass = "$pass"

set smtp_url = "smtp://$addr@$smtps:$smtpp/"
set smtp_pass = "$pass"

set from = "$addr"
set realname = "$name"

set folder = "imaps://$imaps/"
set spoolfile = "+INBOX"
EOF

echo "✅ Mutt configuration generated at ~/.mycal/mail/.muttrc"
